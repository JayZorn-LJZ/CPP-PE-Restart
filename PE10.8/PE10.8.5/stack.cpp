#include "stack.h"

namespace STACK
{
    stack::stack()
    {
        top = 0;
    }
    stack::~stack()
    {
        ;
    }
    item stack::push()
    {
        return array[top--];
    }
    void stack::put(item i)
    {
        array[top++] = i;
    }
    double stack::total() const
    {
        double t {};
        for (int i = 0; i <= top; i++)
            t += array[i].payment;
        return t;
    }
}