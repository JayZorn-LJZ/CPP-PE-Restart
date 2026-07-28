#include <iostream>
#include <cstring>   // 用于 strlen(), strcpy()
using namespace std;

struct stringy {
    char * str;      // 指向一个字符串
    int ct;          // 字符串的长度（不包括 '\0'）
};

// set(), show() 和 show() 的函数原型放在这里
void set(stringy &, const char *);
void show(const stringy &, int c = 1);
void show(const char *, int c = 1);

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    
    set(beany, testing);    // 第一个参数是一个引用，
                            // 分配空间以保存 testing 的副本，
                            // 将 beany 的 str 成员设置为指向该
                            // 新内存块，将 testing 复制到新内存块，
                            // 并设置 beany 的 ct 成员
    show(beany);            // 打印成员字符串一次
    show(beany, 2);         // 打印成员字符串两次
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);          // 打印 testing 字符串一次
    show(testing, 3);       // 打印 testing 字符串三次
    show("Done!");
    return 0;
}

void set(stringy & s, const char * so)
{
    int count = 0;
    for (count = 0; so[count]; count++)
        count++;
    s.str = new char [++count];
    strncpy(s.str, so, count);
    s.ct = count - 1;
}

void show(const stringy & s, int c) // 函数定义的参数列表不能有默认值！！！！
{
    for (int i = 0; i < c; i++)
        cout << s.str << endl;
}

void show(const char * s, int c)
{
    for (int i = 0; i < c; i++)
        cout << s << endl;
}