#include <iostream>
#include <cstring>
#include <string>

// 整形

// 浮点型

// 符合类型

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

union one4all
{
    int int_val;
    long long_val;
    double double_val;
};

enum spectrum {red = 10, orange, yellow, green, blue, violet, indigo, ultraviolet};

int main()
{
    using namespace std;
    
    spectrum s1 = static_cast<spectrum>(1);
    spectrum s2 = green;

    cout << 1 + s1 + s2;


    return 0;
}