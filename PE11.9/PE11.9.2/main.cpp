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
    double target;
    double dstep;

    ofstream file("output.txt");

    dstep= 20;
    target = 100;

    file << "Target Distance : 100, Step Size: 20" << endl;
    file << steps << ": (x, y) = (" << step.xval() << ", " << step.yval() << ")" << endl;

    while (result.magval() < target)
    {
        direction = rand() % 360;                // 随机方向（0~359度）
        step.reset(dstep, direction, Vector::POL); // 用极坐标设置步长
        result = result + step;                  // 累加位移
        steps++;
        file << steps << ": (x, y) = (" << step.xval() << ", " << step.yval() << ")" << endl;
    }

    file << "After " << steps << " steps, the subject has the following lacation: " << endl;
    file << "(x, y) = " << "(" << result.xval() << ", " << result.yval() << ")" << endl;
    file << "or "  << "(m, a) = " << "(" << result.magval() << ", " << result.angval() << ")" << endl;

    file << "Average outward distance per step = " << result.magval() / steps;
    
    file.close();

    // cout << "输入目标距离（输入 q 退出）: ";
    // while (cin >> target)
    // {
    //     cout << "输入步长: ";
    //     if (!(cin >> dstep))
    //         break;

    //     while (result.magval() < target)
    //     {
    //         direction = rand() % 360;                // 随机方向（0~359度）
    //         step.reset(dstep, direction, Vector::POL); // 用极坐标设置步长
    //         result = result + step;                  // 累加位移
    //         steps++;
    //     }

    //     cout << "走了 " << steps << " 步后，当前位置为：\n";
    //     cout << result << endl;                      // 使用重载的 << 输出直角坐标
    //     cout << "或\n";
    //     result.polar_mode();                         // 切换至极坐标模式（若类提供）
    //     cout << result << endl;                      // 输出极坐标
    //     cout << "平均每步向外距离 = "
    //          << result.magval() / steps << endl;

    //     steps = 0;
    //     result.reset(0.0, 0.0);
    //     cout << "输入目标距离（输入 q 退出）: ";
    // }
    // cout << "再见！\n";
    // cin.clear();
    // while (cin.get() != '\n')
    //     continue;
    return 0;
}