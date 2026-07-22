#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    const int ArSize = 100;
    char str_temp[ArSize] {};
    int count {};

    cin >> str_temp;
    while (strcmp(str_temp, "done"))
    {
        count ++;
        cin >> str_temp;
    }
    cout << count;

    return 0;
}