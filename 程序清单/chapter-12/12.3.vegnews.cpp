#include <iostream>
using std::cout;
#include "strngbad.h"

void callme1(StringBad &);
void callme2(StringBad);

int main()
{
    using std::endl;
    {
        cout << "Starting an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight"); // 创建第一个对象， num_strings 为 1
        StringBad headline2("Lettuce Prey"); // 创建第二个对象， num_strings 为 2
        // StringBad sports = StringBad("Spinach Leaves Bowl for Dollars"); // 赋值是不会调用构造函数的，而是调用复制构造函数
        StringBad sports("Spinach Leaves Bowl for Dollars"); // 创建第三个对象， num_strings 为 3

        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;

        callme1(headline1); // 不创建对象
        cout << "headline1: " << headline1 << endl;
        callme2(headline2); // 创建一个自动对象，出现第一次双重释放，重复释放headlin2.str。创建第四个对象， num_strings 为 3
        // 这里调用的是默认复制构造函数，所以创建了新的变量时没有输出，没有将num_strings 加一
        // 释放自动对象，释放headline2.str指向的内存块。调用的是用户定义的析构函数，所以num_strings 会减一。num_strings 为 2
        cout << "headline2: " << headline2 << endl;
        // 为什么这里没有输出？sb在运行完 callme2 的代码之后自动调用了其析构函数，导致 sb 和 headline2 的数据成员 str 共同指向
        // 的内存块被释放。当对 headline2 进行 cout 函数调用的时候，cout 输出 headline2.str 的内容时，其值是指向一块空内存的，所以没有输出

        cout << "Initialize one object to another:\n";

        StringBad sailor = sports; // 复制构造函数。出现第二次双重释放，重复释放sports.str。创建第 4 个对象， num_strings 为 2，不增加num_strings，因为调用的是复制构造函数
        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to another:\n";

        StringBad knot; // 创建第五个对象， num_strings 为 3
        knot = headline1; // 赋值运算符。出现第三次双重释放，重复释放knot.str
        cout << "kont: " << knot << endl;
        cout << "Exiting the block.\n";
    }
    cout << "end of main()\n";
    // 还有五个对象未释放，num_strings 依次减五次，最终值为-2

    // using namespace std;
    // StringBad sb1 = "Jayzorn"; // 隐式转换
    // cout << sb1;

    return 0;
}

void callme1(StringBad & rsb)
{
    cout << "String passed by reference:\n";
    cout << "\"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
    cout << "String passed by value:\n";
    cout << " \"" << sb << "\"\n";
}

// #include <iostream>
// #include <cstring>
// using namespace std;
// class MyClass
// {
//     private:
//         char * MyClassName;
//         static int class_count;
//     public:
//         MyClass(const MyClass & mc)
//         {
//             MyClassName = new char[20];
//             strcpy(MyClassName, mc.MyClassName);
//             class_count++;
//             cout << &mc << ": " << mc.MyClassName << " 被用于复制构造 " << this << ": " << MyClassName << endl;
//             cout << this << ": " << MyClassName << " 对象被创建。" << endl;
//             cout << "已创建 " << class_count << " 个对象" << endl;
//         };
//         MyClass()
//         {
//             MyClassName = new char[20];
//             strcpy(MyClassName, "Jayzorn");
//             class_count++;
//         }
//         MyClass(const char * name)
//         {
//             MyClassName = new char[20];
//             strcpy(MyClassName, name);
//             class_count++;
//             cout << this << ": " << MyClassName << " 对象被创建。" << endl;
//             cout << "已创建 " << class_count << " 个对象" << endl;
//         }
//         ~MyClass()
//         {
//             class_count--;
//             cout << this << ": " << MyClassName << " 对象被删除。" << endl;
//             cout << "还剩 " << class_count << " 个对象。" << endl;
//             delete [] MyClassName;
//         }
//         friend ostream & operator<<(ostream & os, const MyClass & mc)
//         {
//             cout << mc.MyClassName;
//             return os;
//         }
// };

// int MyClass::class_count = 0; // 私有成员定义。并非调用，所以不报错

// int main()
// {
//     // {    
//         MyClass mc1("Phil");
//         MyClass mc2 = mc1; // 测试可得，本编译器的复制构造函数的逻辑是：使用复制构造函数直接创建
//     // }
//     cout << "--------------------------" << endl;
//     // mc1.~MyClass();
//     // mc2.~MyClass();
//     return 0;
// }