#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <iostream>

using std::string;
const int strsize = 40;

class account
{
    string name;
    char account_name[strsize]; // 可以在类声明中声明数组
    int deposit;
    int getsize(const char *);
    public:
        account();
        account(const string &, const char *, int);
        ~account();
        void show() const;
        void save(const int &);
        int take(const int &);
}; // 和结构一样，类的大括号也是声明的一部分

#endif