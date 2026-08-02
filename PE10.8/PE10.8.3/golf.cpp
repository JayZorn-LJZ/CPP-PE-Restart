// #include <iostream>
// #include <cstring>
// #include "golf.h"

// using std::cout, std::cin, std::endl;

// void setgolf(golf & g, const char * name, int hc)
// {
//     strncpy(g.fullname, name, Len);
//     g.handicap = hc;
// }

// int setgolf(golf & g)
// {
//     cout << "Please input fullname: ";
//     cin.getline(g.fullname, Len);
//     cout << "Please input handicap: ";
//     cin >> g.handicap;
//     while (!cin)
//     {
//         cin.clear(); // 清除错误位
//         while (cin.get() != '\n');
//         cout << "Wrong input. Please input handicap: ";
//         cin >> g.handicap;
//     }
//     if (g.fullname[0])
//         return 0;
//     else
//         return 1;
// }

// void handicap(golf & g, int hc)
// {
//     g.handicap = hc;
// }

// void showgolf(const golf & g)
// {
//     cout << "Fullname: " << g.fullname << endl;
//     cout << "Handicap: " << g.handicap << endl;
// }

#include <iostream>
#include <cstring>
#include "golf.h"

golf::golf(const char * s, int h)
{
    using namespace std;
    strncpy(fullname, s, Len);
    handicap = h;
}

golf::golf()
{
    using namespace std;
    golf temp("", 0);
    cout << "Please input fullname: ";
    cin.getline(temp.fullname, Len);
    cout << "Please input handicap: ";
    cin >> temp.handicap;
    while (!cin)
    {
        cin.clear(); // 清除错误位
        while (cin.get() != '\n');
        cout << "Wrong input. Please input handicap: ";
        cin >> temp.handicap;
    }
    if (!fullname[0])
        temp.nonename = true;
    else
        temp.nonename = false;
    *this = temp;
}

golf::~golf()
{

}

void golf::get_handicap(int h)
{
    handicap = h;
}

void golf::showgolf() const
{
    using namespace std;
    cout << "Fullname: " << fullname << endl;
    cout << "Handicap: " << handicap << endl;
}