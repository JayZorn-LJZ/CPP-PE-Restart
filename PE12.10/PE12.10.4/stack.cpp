#include <iostream>
#include "stack.h"

void Stack::copy_stack(const Stack & sk)
{
    for (int i = 0; i < sk.size; i++)
        pitems[i] = sk.pitems[i];
}

Stack::Stack(int n)
{
    pitems = new Item [n];
    size = n;
    top = 0;
}

Stack::Stack(const Stack & st)
{
    Item * temp = pitems;
    pitems = new Item [st.size];
    copy_stack(st);
    delete [] temp;
    size = st.size;
    top = st.top;
}

Stack::~Stack()
{
    delete [] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const Item & item)
{
    if (isfull())
        return false;
    else
    {
        pitems[top] = item;
        top++;
        return true;
    }
}

bool Stack::pop(Item & item)
{
    if (isempty())
        return false;
    else
    {
        top--;
        item = pitems[top];
        return true;
    }
}

Stack Stack::operator=(const Stack & st)
{
    delete [] pitems;
    size = st.size;
    top = st.top;
    pitems = new Item [st.size];
    copy_stack(st);
    return *this;
}