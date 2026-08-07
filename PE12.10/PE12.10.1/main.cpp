#include <iostream>
#include "cow.hpp"

using namespace std;
using namespace COW;

int main()
{
    {
        using namespace std;

        Cow cow1{};
        Cow cow2("Jay");
        Cow cow3 = {};
        Cow cow4 = "Phil"; // 转换函数

        cow1.ShowCow();
        cow2.ShowCow();
        cow3.ShowCow();
        cow4.ShowCow();

        cout << "1. ---------------------------------" << endl;

        cow3 = cow4;
        cow3.ShowCow();

        cout << "2. ---------------------------------" << endl;

        cow4 = {"JayZorn", "Coding", 90.0}; // 将调用operator=运算符函数，右值被传递给一个临时变量并用于初始化，将临时变量初始化const Cow & c引用，最后进入函数块运行代码完成赋值
        cow4.ShowCow();
        cout << Cow::getCowSize() << endl;
    }

    return 0;
}