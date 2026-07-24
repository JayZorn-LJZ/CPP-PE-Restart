#include <iostream>

using namespace std;

int main(void)
{
    int input {};
    int total {};
    cin >> input; // 这种读取方式会把输入流中的空白去掉
    while (input != 0)
    {
        total += input;
        cout << total;
        cin >> input;
    }

    return 0;
}