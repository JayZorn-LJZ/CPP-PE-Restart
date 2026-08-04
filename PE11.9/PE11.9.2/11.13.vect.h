#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
#include <cmath>
namespace VECTOR
{
    using std::sqrt;
    using std::sin;
    using std::cos;
    using std::atan;
    using std::atan2;
    class Vector
    {
        public:
            enum Mode {RECT, POL};
        private:
            double x;
            double y;
            // double mag;
            // double ang;
            Mode mode;
            // void set_mag();
            // void set_ang();
            void set_x(double, double);
            void set_y(double, double);
        public:
            Vector();
            Vector(double, double, Mode form = RECT);
            void reset(double, double, Mode form = RECT);
            ~Vector();
            double xval() const {return x;}
            double yval() const {return y;}
            // double magval() const {return mag;}
            double magval() const {return sqrt(x * x + y * y);}
            // double angval() const {return ang;}
            double angval() const 
            {    
                if (x == 0.0 && y == 0.0)
                    return 0.0;
                else
                    return atan2(y, x);
            }
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