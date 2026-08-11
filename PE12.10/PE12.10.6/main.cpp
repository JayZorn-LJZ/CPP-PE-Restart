// 编程练习 12.6 —— 两台 ATM、两个队列：求平均等候 1 分钟时每小时到达人数
// 规则：第一队人数少于第二队时进第一队，否则进第二队（两队人数相同时进第二队）
// 注意：这是非线性问题，答案不会简单等于 12.5 的两倍。
// 编译：g++ main.cpp 12.11.queue.cpp -o main.exe -std=c++11
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "12.10.queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x)
{
    return std::rand() * x / RAND_MAX < 1;
}

// 对某个 perhour 模拟 runs 次，返回平均等候时间（分钟）
double simulate(double perhour, int hours, int runs = 3)
{
    long cyclelimit = MIN_PER_HR * hours;
    double min_per_cust = MIN_PER_HR / perhour;
    double total_avg = 0.0;

    for (int r = 0; r < runs; r++)
    {
        Queue line1, line2;         // 两台 ATM 各一个队列，默认容量各 10
        long turnaways = 0;         // 因两个队都满而离开的人数
        long customers = 0;
        long served = 0;
        long line_wait = 0;         // 两个队所有顾客等待时间之和
        int wait_time1 = 0;         // ATM1 当前顾客剩余服务时间
        int wait_time2 = 0;         // ATM2 当前顾客剩余服务时间
        Item temp1, temp2;

        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))
            {
                if (line1.isfull() && line2.isfull())
                    turnaways++;    // 两队都满，顾客离开
                else
                {
                    customers++;
                    // 第一队人少进第一队；否则（含两队人数相同）进第二队
                    if (line1.queuecount() < line2.queuecount())
                    {
                        temp1.set(cycle);
                        line1.enqueue(temp1);
                    }
                    else
                    {
                        temp2.set(cycle);
                        line2.enqueue(temp2);
                    }
                }
            }

            // ATM1 空闲且第一队非空：队首顾客开始被服务
            if (wait_time1 <= 0 && !line1.isempty())
            {
                line1.dequeue(temp1);
                wait_time1 = temp1.ptime();
                line_wait += cycle - temp1.when();
                served++;
            }

            // ATM2 空闲且第二队非空：同样处理
            if (wait_time2 <= 0 && !line2.isempty())
            {
                line2.dequeue(temp2);
                wait_time2 = temp2.ptime();
                line_wait += cycle - temp2.when();
                served++;
            }

            if (wait_time1 > 0)
                wait_time1--;
            if (wait_time2 > 0)
                wait_time2--;
        }

        if (served > 0)
            total_avg += double(line_wait) / served;
    }

    return runs > 0 ? total_avg / runs : -1.0;
}

int main()
{
    using std::cout;
    using std::endl;

    const int HOURS = 100;      // 试验时间：100 小时
    std::srand(std::time(0));

    cout << "perhour -> average wait (min)\n";
    int best = 1;
    double best_diff = 1e9, best_avg = 0.0;
    for (int perhour = 1; perhour <= 120; perhour++)
    {
        double avg = simulate(perhour, HOURS);
        if (perhour >= 5 && avg <= 5.0)
            cout << perhour << " -> " << avg << endl;
        double diff = avg > 1.0 ? avg - 1.0 : 1.0 - avg;
        if (diff < best_diff)
        {
            best_diff = diff;
            best = perhour;
            best_avg = avg;
        }
    }

    double fine = best, fine_avg = best_avg;
    for (int k = 0; k <= 20; k++)
    {
        double perhour = best - 1.0 + k / 10.0;
        double avg = simulate(perhour, HOURS);
        double diff = avg > 1.0 ? avg - 1.0 : 1.0 - avg;
        if (diff < best_diff)
        {
            best_diff = diff;
            fine = perhour;
            fine_avg = avg;
        }
    }

    cout << "\n--- 结果 ---\n";
    cout << "平均等候 1 分钟对应的到达率：约 " << fine << " 人/小时"
         << "（模拟平均等待 " << fine_avg << " 分钟）\n";
    cout << "取整数每小时到达人数：" << best << " 人/小时时平均等待约 "
         << best_avg << " 分钟\n";
    return 0;
}
