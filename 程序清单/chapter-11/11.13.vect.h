#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace VECTOR
{
    class Vector
    {
        public:
            enum Mode {RECT, POL};
        private:
            double x;
            double y;
            double mag;
            double ang;
            Mode mode;
            void set_mag();
            void set_ang();
            void set_x();
            void set_y();
        public:
            Vector();
            Vector(double, double, Mode form = RECT);
            void reset(double, double, Mode form = RECT);
            ~Vector();
            double xval() const {return x;}
            double yval() const {return y;}
            double magval() const {return mag;}
            double angval() const {return ang;}
            void polar_mode();
            void rect_mode();
            Vector operator+(const Vector &) const;
            Vector operator-(const Vector &) const;
            Vector operator-() const;
            Vector operator*(double) const;
            friend Vector operator*(double, const Vector & );
            friend std::ostream & operator<<(std::ostream &, const Vector &);
    };
}

#endif