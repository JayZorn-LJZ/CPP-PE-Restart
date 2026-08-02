#ifndef PE964_H_
#define PE964_H_

namespace SALES
{
    const int QUARTERS = 4;
    // struct Sales
    // {
    //     double sales[QUARTERS];
    //     double average;
    //     double max;
    //     double min;
    // };
    // void setSales(Sales & s, const double ar[], int n);
    // void setSales(Sales & s);
    // void showSales(const Sales & s);
    // void sort_sales(double *, int);

    class Sales
    {
        double sales[QUARTERS];
        double average;
        double max;
        double min;
        void sort_sales(double *, int);
        public:
            Sales();
            Sales(const double *, int);
            void showSales() const;
    };

}

#endif