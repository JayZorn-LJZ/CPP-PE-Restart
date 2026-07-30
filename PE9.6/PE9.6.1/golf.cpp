#include <iostream>
#include <cstring>
#include "golf.h"

using std::cout, std::cin, std::endl;

void setgolf(golf & g, const char * name, int hc)
{
    strncpy(g.fullname, name, Len);
    g.handicap = hc;
}

int setgolf(golf & g)
{
    cout << "Please input fullname: ";
    cin.getline(g.fullname, Len);
    cout << "Please input handicap: ";
    cin >> g.handicap;
    while (!cin)
    {
        cin.clear(); // 清除错误位
        while (cin.get() != '\n');
        cout << "Wrong input. Please input handicap: ";
        cin >> g.handicap;
    }
    if (g.fullname[0])
        return 0;
    else
        return 1;
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    cout << "Fullname: " << g.fullname << endl;
    cout << "Handicap: " << g.handicap << endl;
}