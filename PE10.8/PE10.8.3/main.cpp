#include <iostream>
#include "golf.h"

int main(void)
{
    using namespace std;

    golf g;
    if (g.emptyname())
        cout << "g.fullname is null.\n";
    g.showgolf();

    golf g1 {"Phil", 12};
    g1.showgolf();

    g1.get_handicap(18);
    g1.showgolf();

    return 0;
}