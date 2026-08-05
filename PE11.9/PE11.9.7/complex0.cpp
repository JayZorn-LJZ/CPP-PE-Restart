#include "complex0.h"

complex::complex()
{
    r = 0;
    i = 0;
}

complex::complex(double n1, double n2)
{
    r = n1;
    i = n2;
}

complex complex::operator +(const complex & cx) const
{
    complex temp;
    temp.r = r + cx.r;
    temp.i = i + cx.i;
    return temp;
}

complex complex::operator -(const complex & cx) const
{
    complex temp;
    temp.r = r - cx.r;
    temp.i = i - cx.i;
    return temp;
}

complex complex::operator *(const complex & cx) const
{
    complex temp;
    temp.r = r * cx.r - i * cx.i;
    temp.i = r * cx.i + i * cx.r;
    return temp;
}

complex complex::operator /(const complex & cx) const
{
    complex temp;
    temp.r = r / cx.r;
    temp.i = i / cx.i;
    return temp;
}

complex operator *(double n, const complex & cx) 
{
    complex temp;
    temp.r = n * cx.r;
    temp.i = n * cx.i;
    return temp;
}

complex complex::operator ~() const
{
    complex temp = *this;
    temp.i = -i;
    return temp;
}

std::ostream & operator <<(std::ostream & os, const complex & cx)
{
    os << "(" << cx.r << ", " << cx.i << "i)";
    return os;
}

std::istream & operator >>(std::istream & os, complex & cx)
{
    std::cout << "real:";
    os >> cx.r;
    while (!os)
    {
        return os;
        // os.clear();
        // while (os.get() != '\n');
        // std::cout << "Error input. real: ";
        // os >> cx.r;
    }
    std::cout << "imaginary:";
    os >> cx.i;
    while (!os)
    {
        return os;
        // os.clear();
        // while (os.get() != '\n');
        // std::cout << "Error input. imaginary: ";
        // os >>cx.i;
    }
    return os;
}