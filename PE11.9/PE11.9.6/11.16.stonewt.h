// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>

class Stonewt
{
private:
    enum {Lbs_per_stn = 14};      // pounds per stone
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds
public:
    Stonewt(double lbs);          // constructor for double pounds
    Stonewt(int stn, double lbs); // constructor for stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    void show_lbs() const;        // show weight in pounds format
    void show_stn() const;        // show weight in stone format
    // 重载六个关系运算符：> ; < ; == ; != ; ! ; <= ; >=
    bool operator <(const Stonewt &) const;
    bool operator >(const Stonewt &) const;
    bool operator <=(const Stonewt &) const;
    bool operator >=(const Stonewt &) const;
    bool operator !=(const Stonewt &) const;
    bool operator ==(const Stonewt &) const;
    friend std::istream & operator >>(std::istream &, Stonewt &);
    friend std::ostream & operator <<(std::ostream &, const Stonewt &);
};
#endif