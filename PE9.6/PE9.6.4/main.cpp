#include <iostream>
#include "PE9.6.4.h"

using namespace std;
using namespace SALES;

int main(void)
{
    Sales s;

    // setSales(s);
    // showSales(s);

    double a[QUARTERS+3] {8.9, 7.4, 10.9, 2.0, 8.8, 9.0, 8.8};
    setSales(s, a, QUARTERS+3);
    showSales(s);

    return 0;
}