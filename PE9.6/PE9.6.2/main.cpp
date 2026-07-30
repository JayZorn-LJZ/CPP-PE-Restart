// static.cpp -- using a static local variable
#include <iostream>
using namespace std;

// function prototype
void strcount(const string & str);

int main()
{
    string input;

    cout << "Enter a line:\n";
    getline(cin, input);
    while (cin)
    {
        if (input == "")
            return 0;
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        getline(cin, input);
    }
    cout << "Bye\n";
    return 0;
}

void strcount(const string & str)
{
    using namespace std;
    static int total = 0;        // static local variable

    cout << "\"" << str << "\" contains ";
    total += str.size();
    cout << str.size() << " characters\n";
    cout << total << " characters total\n";
}