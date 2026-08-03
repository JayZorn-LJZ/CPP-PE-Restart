#include <iostream>
#include "move.h"

int main(void)
{
    move m1;
    m1.showmove();
    m1 = move(1, 2);
    m1.showmove();
    m1.reset(2,3);
    m1.showmove();
    m1.add(move(1,1));
    m1.showmove();

    return 0;
}