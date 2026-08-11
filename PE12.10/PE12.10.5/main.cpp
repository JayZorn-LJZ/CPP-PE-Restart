// 编程练习 12.5 —— 单台 ATM：找出使平均等候时间为 1 分钟时，每小时到达的客户数
// 试验时间不少于 100 小时。
// 编译：g++ main.cpp 12.11.queue.cpp -o main.exe -std=c++11
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "12.10.queue.h"

const int MIN_PER_HR = 60;

// 判断这一分钟有没有顾客到达。
// x = 平均每多少分钟来一位顾客；rand()*x/RAND_MAX 均匀落在 [0, x)，
// 小于 1 的概率是 1/x，正好对应“每分钟到达概率 = 1/x”。
bool newcustomer(double x)
{
    return std::rand() * x / RAND_MAX < 1;
}

// 对某个 perhour（每小时到达人数）模拟 runs 次，返回平均等候时间（分钟）
double simulate(double perhour, int hours, int runs = 3)
{
    long cyclelimit = MIN_PER_HR * hours;   // 模拟的总分钟数
    double min_per_cust = MIN_PER_HR / perhour; // 平均每多少分钟来一位顾客
    double total_avg = 0.0;

    for (int r = 0; r < runs; r++)
    {
        Queue line;                 // 一个队列，默认最大容量 10
        long turnaways = 0;         // 因队列满而离开的人数
        long customers = 0;         // 入队人数
        long served = 0;            // 已被服务的人数
        long sum_line = 0;          // 每分钟队列长度之和
        long line_wait = 0;         // 所有顾客等待时间之和
        int wait_time = 0;          // 当前顾客剩余服务时间
        Item temp;

        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))
            {
                if (line.isfull())
                    turnaways++;    // 队列满，顾客直接离开
                else
                {
                    customers++;
                    temp.set(cycle);      // 记录到达时间，随机生成 1~3 分钟服务时间
                    line.enqueue(temp);   // 顾客入队
                }
            }

            // 柜台空闲且队列非空：队首顾客开始被服务
            if (wait_time <= 0 && !line.isempty())
            {
                line.dequeue(temp);
                wait_time = temp.ptime();          // 本次服务需要 1~3 分钟
                line_wait += cycle - temp.when();  // 等待时间 = 开始服务时刻 - 到达时刻
                served++;
            }

            if (wait_time > 0)
                wait_time--;        // 每分钟服务时间减 1

            sum_line += line.queuecount();  // 统计当前队列长度
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

    const int HOURS = 100;      // 试验时间：100 小时（满足“不少于 100 小时”）
    std::srand(std::time(0));

    // 1) 整数粗扫：遍历 1~120 人/小时，看哪个最接近 1 分钟
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

    // 2) 在 best 附近按 0.1 细分，找更精确的到达率
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
