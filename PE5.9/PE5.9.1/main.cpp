#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int small {};
    int big {};
    int total {};

    cout << "please input two number: ";
    cin >> small;
    cin >> big;

    for (int i = small; i <= big; i++)
    {
        total += i;
    }

    cout << "the total is " << total;

    return 0;
}