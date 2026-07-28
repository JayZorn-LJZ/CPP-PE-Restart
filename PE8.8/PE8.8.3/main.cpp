#include <iostream>
#include <string>
#include <cctype>

using namespace std;
void change(string &);

int main()
{
    string s {};
    while (cin)
    {
        cout << "Enter a string (Ctrl Z and enter to quit):";
        getline(cin, s);
        change(s);
        cout << s << endl;
    }

    return 0;
}

void change(string & s)
{
    for (char & ch : s)
        ch = toupper(ch);
}