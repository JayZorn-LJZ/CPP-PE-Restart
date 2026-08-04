#include <iostream>
#include "11.16.stonewt.h"
using namespace std;

int main(void)
{
    // 构造
    Stonewt st1 {10, 1.0, 1};
    cout << "st1: " << st1;
    Stonewt st2 = 100.0; // 转换函数
    cout << "st2: " << st2;
    Stonewt st3 = st2 + 10; // 复制构造函数
    cout << "st3: "  << st3;
    
    cout << st1 + st2;
    cout << st2 * st3;
    cout << st1 - st3;

    return 0;
}