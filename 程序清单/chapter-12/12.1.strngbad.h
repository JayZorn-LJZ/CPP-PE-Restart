#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_

class StringBad
{
    private:
        char * str;
        int len;
        static int num_strings;
        // static const int num_strings = 0;
    public:
        StringBad(const char * s); // 构造函数
        // StringBad(const StringBad &); // 复制构造函数
        StringBad(); // 默认构造函数
        ~StringBad(); // 析构函数
        // StringBad & operator=(const StringBad &); // 赋值运算符函数
        friend std::ostream & operator<<(std::ostream & os, const StringBad & s);
};

#endif