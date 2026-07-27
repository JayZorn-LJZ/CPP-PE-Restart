#include <iostream>

using namespace std;

int compute(int);

int main(void)
{
    cout << compute(3);
    return 0;
}

int compute(int num)
{
    if ((num - 1) == 0)
        return num;
    return num * compute(num - 1);
}