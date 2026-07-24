#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    string str_temp {};
    int count {};

    cin >> str_temp;
    while (str_temp != "done")
    {
        count ++;
        cin >> str_temp;
    }
    cout << count;

    return 0;
}