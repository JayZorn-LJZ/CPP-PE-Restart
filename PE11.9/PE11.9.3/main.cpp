// randwalk.cpp -- 使用 Vector 类模拟随机漫步
// 与 vect.cpp 一起编译

#include <iostream>
#include <fstream>
#include <cstdlib>   // rand(), srand() 原型
#include <ctime>     // time() 原型
#include "11.13.vect.h"    // Vector 类声明

int main()
{
    using namespace std;
    using VECTOR::Vector;

    srand(time(0));             // 初始化随机数生成器
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    unsigned long total_steps = 0;
    unsigned long step_count = 0;
    unsigned long highest_steps = 0;
    unsigned long lowest_steps = 0;
    unsigned long average_steps = 0;
    double target;
    double dstep;
    

    cout << "输入目标距离（输入 q 退出）: ";
    while (cin >> target)
    {
        cout << "输入步长: ";
        if (!(cin >> dstep))
            break;

        while (result.magval() < target)
        {
            direction = rand() % 360;                // 随机方向（0~359度）
            step.reset(dstep, direction, Vector::POL); // 用极坐标设置步长
            result = result + step;                  // 累加位移
            steps++;
        }
        
        total_steps += steps;
        highest_steps = highest_steps < steps ? steps : highest_steps;
        if (!lowest_steps)
            lowest_steps = steps;
        else
            lowest_steps = lowest_steps > steps ? steps : lowest_steps;

        cout << "走了 " << steps << " 步后，当前位置为：\n";
        cout << result << endl;                      // 使用重载的 << 输出直角坐标
        cout << "或\n";
        result.polar_mode();                         // 切换至极坐标模式（若类提供）
        cout << result << endl;                      // 输出极坐标
        cout << "平均每步向外距离 = "
             << result.magval() / steps << endl;

        steps = 0;
        result.reset(0.0, 0.0);
        step_count++;
        cout << "输入目标距离（输入 q 退出）: ";
    }
    cout << "再见！\n";

    average_steps = total_steps / step_count;

    cout << "最高步数：" << highest_steps << endl;
    cout << "最低步数：" << lowest_steps << endl;
    cout << "平均步数：" << average_steps << endl;

    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}