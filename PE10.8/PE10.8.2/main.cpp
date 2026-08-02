#include <iostream>
#include "person.h"

int main(void)
{
    using namespace std;
    using namespace PERSON;
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    one.show();
    cout << endl;
    one.formalshow();

    two.show();
    cout << endl;
    two.formalshow();

    three.show();
    cout << endl;
    three.formalshow();
    return 0;
}