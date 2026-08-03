#include <iostream>
#include "plorg.h"

int main(void)
{
    Plorg pl1 {"jayzorn", 100};
    pl1.report();
    Plorg pl2;
    pl2.report();

    return 0;
}