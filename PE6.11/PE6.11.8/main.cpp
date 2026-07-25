#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    ifstream file;
    file.open("test.txt");

    char ch;
    while (file.get(ch))
    {
        cout << ch;
    }

    file.close();
    return 0;
}