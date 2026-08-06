#include <iostream>
#include "13.4.tabtenn1.h"

int main()
{
    using std::cout;
    using std::cin;

    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatedPlayer rplayer(1140, "Mallory", "Duck", true);

    rplayer.Name();
    

    return 0;
}