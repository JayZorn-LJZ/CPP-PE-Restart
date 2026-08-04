// stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout;
#include "11.16.stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, int f)
{
    form = f;
    stone = int (lbs) / Lbs_per_stn;    // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, int f)
{
    form = f;
    stone = stn;
    pds_left = lbs;
    pounds =  stn * Lbs_per_stn +lbs;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
    form = form_pounds_double;
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()         // destructor
{
}

// show weight in stones
// void Stonewt::show_stn() const
// {
//     cout << stone << " stone, " << pds_left << " pounds\n";
// }

// // show weight in pounds
// void Stonewt::show_lbs() const
// {
//     cout << pounds << " pounds\n";
// }

Stonewt Stonewt::operator +(const Stonewt & st) const
{
    Stonewt stonewt;
    stonewt.pounds = (pounds + st.pounds);
    stonewt.stone = int(stonewt.pounds) / Lbs_per_stn;
    stonewt.pds_left = int(stonewt.pounds) % Lbs_per_stn + stonewt.pounds - int(stonewt.pounds);
    return stonewt;
}

Stonewt Stonewt::operator -(const Stonewt & st) const
{
    Stonewt stonewt;
    stonewt.pounds = (pounds - st.pounds);
    stonewt.stone = int(stonewt.pounds) / Lbs_per_stn;
    stonewt.pds_left = int(stonewt.pounds) % Lbs_per_stn + stonewt.pounds - int(stonewt.pounds);
    return stonewt;
}

Stonewt Stonewt::operator *(const Stonewt & st) const
{
    Stonewt stonewt;
    stonewt.pounds = (pounds * st.pounds);
    stonewt.stone = int(stonewt.pounds) / Lbs_per_stn;
    stonewt.pds_left = int(stonewt.pounds) % Lbs_per_stn + stonewt.pounds - int(stonewt.pounds);
    return stonewt;
}

std::ostream & operator << (std::ostream & os, const Stonewt & st)
{
    switch (st.form)
    {
        case Stonewt::form_stone:
            os << st.stone << " stone, " << st.pds_left << " pounds\n";
            break;
        case Stonewt::form_pounds_double:
            os << st.pounds << " pounds\n";
            break;
        case Stonewt::form_pounds_int:
            os << int (st.pounds + 0.5) << " pounds\n";
            break;
    }
    return os;
}