#include <iostream>

using namespace std;
const int SLEN = 30;
struct student{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};
int getinfo(student pa[], int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;
    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Done\n";
    return 0;
}

int getinfo(student * pa, int n)
{
    char ch {};
    for (int i = 0; i < n; i++)
    {
        cout << "Please input the " << i << " student's name: ";
        cin >> pa[i].fullname;
        if (pa[i].fullname[0] == '\n')
            return i - 1;
        cout << "Please input the " << i << "student's " << "hobby: " ;
        cin >> pa[i].hobby;
        cout << "Please input the " << i << "student's " << "ooplevel: " ;
        cin >> pa[i].ooplevel;
    }
    return n;
}

void display1(student ps)
{
    cout << "Display1:\n";
    cout << "Fullname: " << ps.fullname << endl;
    cout << "hobby: " << ps.hobby << endl;
    cout << "ooplevel: " << ps.ooplevel << endl;
}

void display2(const student * ps)
{
    cout << "Display2:\n";
    cout << "Fullname: " << ps->fullname << endl;
    cout << "hobby: " << ps->hobby << endl;
    cout << "ooplevel: " << ps->ooplevel << endl;
}

void display3(const student * ps, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Display3:\n";
        cout << "Fullname: " << ps[i].fullname << endl;
        cout << "hobby: " << ps[i].hobby << endl;
        cout << "ooplel: " << ps[i].ooplevel << endl;
    }
}