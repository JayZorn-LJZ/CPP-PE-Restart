#include <iostream>
#include <algorithm>  // 需要这个头文件来使用 std::swap
#include "sales.h"

namespace SALES
{
    Sales::Sales(const double * ar, int n)
    {
        using std::cout, std::endl, std::cin;
        int index = (QUARTERS > n ? n : QUARTERS) - 1;
        double * temp = new double [index + 1];
        for (int i = 0; i < index + 1; i++)
            temp[i] = ar[i];
        sort_sales(temp, index + 1);
        double total = 0;
        for (int i = 0; i < QUARTERS; i++)
        {
            if (i < index + 1)
                sales[i] = temp[i];
            else
                sales[i] = 0;
            total += sales[i];
        }
        average = total / QUARTERS;
        max = temp[0];
        min = temp[index];

        delete [] temp;
    }

    Sales::Sales()
    {
        using std::cout, std::endl, std::cin;
        double total = 0;
        double * temp = new double [QUARTERS];
        for (int i = 0; i < QUARTERS; i++)
        {
            cout << "Please input " << i << ". sales: ";
            cin >> sales[i];
            while (!cin)
            {
                cin.clear();
                while (cin.get() != '\n')
                    ;
                cout << "Wrong input. Please input " << i << ". sales: ";
                cin >> sales[i];
            }
            temp[i] = sales[i];
            total += sales[i];
        }

        average = total / QUARTERS;
        sort_sales(temp, QUARTERS);
        max = temp[0];
        min = temp[QUARTERS - 1];

        delete [] temp;
    }

    void Sales::sort_sales(double * array, int n)
    {
        int index = n - 1;
        for (double * p1 = array; p1 < (array + index); p1++)
            for (double * p2 = p1 + 1; p2 <= (array + index); p2++)
            {
                if (*p1 < *p2)
                    std::swap(*p1,*p2);
            }
    }

    void Sales::showSales() const
    {
        using std::cout, std::endl, std::cin;
        cout << "All Sales: " << endl;
        for (int i = 0; i < QUARTERS; i++)
            cout << i+1 << ". " << sales[i] << endl;
        cout << "Average: " << average << endl;
        cout << "Max: " << max << endl;
        cout << "Min: "  << min << endl;
    }
}