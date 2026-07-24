#include <iostream>

using namespace std;

const int strsize = 40;
const int ArSize = 4;

int main(void)
{
    struct bop {
        char fullname[strsize];
        char title[strsize];
        char bopname[strsize];
        int preference;
    };

    bop members[ArSize] =
    {
        { "Liam Carter",     "Software Engineer",     "CipherFox", 2 },
        { "Emma Thompson",   "Data Analyst",          "NightOwl",  0 },
        { "Noah Anderson",   "Embedded Developer",    "IronByte",  1 },
        { "Sophia Mitchell", "Cybersecurity Expert",  "Shadow",    2 }
    };

    enum {a = 'a', b, c, d};

    char temp {};

    cout << "Benevolent Order of Programmers Report" << endl
    << "a. display by name  b. display by title" << endl
    << "c. display by bopname d. display by preference" << endl
    << "q. quit" << endl;

    cout << "enter your choice: ";
    cin >> temp;
    while (temp != 'q')
    {
        switch (temp)
        {
            case a:
                for (int i = 0; i < ArSize; i++)
                    cout << members[i].fullname << endl;
                break;
            case b:
                for (int i = 0; i < ArSize; i++)
                    cout << members[i].title << endl;
                break;
            case c:
                for (int i = 0; i < ArSize; i++)
                    cout << members[i].bopname << endl;
                break;
            case d:
                for (int i = 0; i < ArSize; i++)
                    switch (i)
                    {
                        case 0:
                            cout << members[i].fullname << endl;
                            continue;
                        case 1:
                            cout << members[i].title << endl;
                            continue;
                        case 2:
                            cout << members[i].bopname << endl;
                            continue;
                    }
                break;
        }
        cout << "Next choice: ";
        cin >> temp;
    }

    return 0;
}