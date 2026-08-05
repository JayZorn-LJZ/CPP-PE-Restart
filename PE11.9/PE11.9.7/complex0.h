#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>

class complex
{
    private:
        double r;
        double i;
    public:
        complex();
        complex(double n1, double n2 = 0.0);
        ~complex() {};
        complex operator +(const complex &) const;
        complex operator -(const complex &) const;
        complex operator *(const complex &) const;
        complex operator /(const complex &) const;
        friend complex operator *(double, const complex &);
        complex operator ~() const;
        friend std::ostream & operator <<(std::ostream &, const complex &);
        friend std::istream & operator >>(std::istream &, complex &);
};

#endif