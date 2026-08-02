#include <iostream>
#include <cstring>
#include "person.h"

namespace PERSON
{
    using namespace std;
    Person::Person(const string & s, const char * fn)
    {
        lname = s;
        strncpy(fname, fn, LIMIT);
    }
    void Person::show() const
    {
        std::cout << fname << " " << lname << endl;
    }
    void Person::formalshow() const
    {
        std::cout << lname << " " << fname << endl;
    }
}