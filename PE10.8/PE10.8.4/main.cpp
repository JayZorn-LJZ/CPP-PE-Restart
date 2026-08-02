#include <iostream>
#include "sales.h"

using namespace std;
using namespace SALES;

int main(void)
{
    double a[QUARTERS+3] {8.9, 7.4, 10.9, 2.0, 8.8, 9.0, 8.8};
    Sales s(a, QUARTERS+3);
    s.showSales();

    // setSales(s);
    // showSales(s);

    // showSales(s);

    return 0;
}