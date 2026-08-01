#include <cstring>
#include "account.h"

account::account()
{
    name = "None";
    strncpy(account_name, "none", 5); // strncpy 只会拷贝指定数目的字符，不会自动在字符串末尾加上空字符
    deposit = 0;
}

account::account(const string & n, const char * a, int d)
{
    name = n;
    strcpy(account_name, a);
    // strncpy(account_name, a, getsize(a));
    deposit = d;
}

account::~account()
{
    std::cout << "Delete.\n";
}

int account::getsize(const char * s)
{
    int total = 0;
    for (int i = 0; s[i]; i++)
        total++;
    return ++total;
}

void account::show() const
{
    using namespace std;
    cout << "Name: " << name << endl;
    cout << "Account: " << account_name << endl;
    cout << "Deposit: " << deposit << endl;
}

void account::save(const int & money)
{
    deposit += money;
}

int account::take(const int & money)
{
    deposit -= money;
    return money;
}