#include "13.1.tabtenn0.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string & fn = "none", 
        const string & ln = "none", bool ht = false) : lastname(ln), hasTable(ht), firstname(fn)
{

}

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}