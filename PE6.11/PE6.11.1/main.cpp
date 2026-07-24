#include <iostream>
#include <cctype>

using namespace std;

int main(void)
{
    char ch {};

    // while ((ch = cin.get()) != '@')
    // {
    //     if (islower(ch))
    //         cout << char(toupper(ch));
    //     else if (isupper(ch))
    //         cout << char(tolower(ch));
    //     else
    //         cout << char(ch);
    // }

    while (!(cin.get(ch)).eof()) // 注意，eof() 检查到没有到文件尾时返回的是false
    {
        if (islower(ch))
            cout << char(toupper(ch));
        else if (isupper(ch))
            cout << char(tolower(ch));
        else
            cout << char(ch);
    }

    return 0;
}