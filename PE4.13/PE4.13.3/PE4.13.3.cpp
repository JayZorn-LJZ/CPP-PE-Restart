#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    char fname[20]{};
    char lname[20]{};

    cout << "Enter your first name:";
    cin >> fname;
    // cin.get();
    cout << "Enter your last name:";
    cin >> lname;

    cout << "Heres the information in a single string: " << lname << ", " << fname;

    return 0;
}