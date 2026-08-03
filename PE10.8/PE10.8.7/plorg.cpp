#include <iostream>
#include <cstring>
#include "plorg.h"

Plorg::Plorg(const char * n, int c)
{
    strncpy(name, n, 19);
    ci = c;
}

Plorg::Plorg()
{
    strncpy(name, "Plorga", 19);
    ci = 50;
}

Plorg::~Plorg()
{
    ;
}

void Plorg::set_ci(int c)
{
    ci = c;
}

void Plorg::report() const
{
    using namespace std;
    cout << "Name: " << name << endl;
    cout << "CI: " << ci << endl;
}