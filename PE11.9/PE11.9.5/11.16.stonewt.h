// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt
{
private:
    // enum {Lbs_per_stn = 14};      // pounds per stone
    enum constant {Lbs_per_stn = 14, form_stone = 0, form_pounds_int, form_pounds_double};      // pounds per stone
    int form;
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds
public:
    Stonewt(double lbs, int f = form_pounds_double);          // constructor for double pounds
    Stonewt(int stn, double lbs, int f = form_stone); // constructor for stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    // void show_lbs() const;        // show weight in pounds format
    // void show_stn() const;        // show weight in stone format
    Stonewt operator +(const Stonewt &) const;
    Stonewt operator -(const Stonewt &) const;
    // Stonewt & operator -() const; 对磅数取负值没有意义
    Stonewt operator *(const Stonewt &) const;
    friend std::ostream & operator << (std::ostream &, const Stonewt &);
};
#endif