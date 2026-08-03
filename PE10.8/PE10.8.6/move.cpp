#include <iostream>
#include "move.h"

move::move(double a, double b)
{
    x = a;
    y = b;
}

void move::showmove() const
{
    using namespace std;
    cout << "X: " << x << endl << "Y: " << y << endl;
}

move move::add(const move & m)
{
    x = x + m.x;
    y = y + m.y;
    return move(move::x, move::y);
}

void move::reset(double a, double b)
{
    x = a;
    y = b;
}
