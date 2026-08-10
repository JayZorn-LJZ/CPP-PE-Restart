#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack sk1(4);
    // cout << sk1.isempty() << endl;
    for (int i = 0; i < 4; i++)
        sk1.push(i); // cout << sk1.push(i) << endl;

    Item i1 = 19;
    // cout << sk1.isfull() << endl;
    cout << sk1.pop(i1) << endl;
    // cout << sk1.isempty() << endl;
    // cout << i1 << endl;

    Stack sk2(sk1);
    cout << sk2.pop(i1) << endl;
    cout << i1 << endl;
    sk1.pop(i1);
    cout << i1;

    return 0;
}