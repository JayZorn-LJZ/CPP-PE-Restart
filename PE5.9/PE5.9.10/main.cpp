#include <iostream>

using namespace std;

int main(void)
{
    int num {};
    cout << "Input your num: ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        for (int x = 1; x < num - i; x++)
            cout << ".";
        for (int y = 0; y <= i; y++)
            cout << "*";
        cout << endl;
    }
}