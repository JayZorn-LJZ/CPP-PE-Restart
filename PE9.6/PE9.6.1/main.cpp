#include <iostream>
#include "golf.h"

int main(void)
{
    using namespace std;

    golf g {};
    if (setgolf(g))
        cout << "g.fullname is null.\n";
    showgolf(g);

    golf g1 {};
    setgolf(g1, "Phil", 12);
    showgolf(g1);

    handicap(g1, 18);
    showgolf(g1);

    return 0;
}