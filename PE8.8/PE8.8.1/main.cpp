#include <iostream>

using namespace std;
int count = 0;
void func(const char *, const int n = 0);

int main(void)
{
    char str[20] = "Hello world";
    func(str);
    func(str, 10);
    func(str, 10);
    func(str, 10);
    func(str, 10);
    func(str, 10);
    func(str, 10);
    func(str, 10);

    return 0;
}

void func(const char * str, const int n)
{
    count++;
    if (n)
    {    
        cout << "print " << count << " times" << endl;
        for (int i = 0; i < count; i++)
            cout << str << endl;
        cout << endl;
    }
    else
        cout << str << endl << endl;
}