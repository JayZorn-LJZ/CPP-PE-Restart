#include <iostream>
#include <algorithm>  // 需要这个头文件来使用 std::swap
#include "PE9.6.4.h"

namespace SALES
{
    void setSales(Sales & s, const double ar[], int n)
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
                s.sales[i] = temp[i];
            else
                s.sales[i] = 0;
            total += s.sales[i];
        }
        s.average = total / QUARTERS;
        s.max = temp[0];
        s.min = temp[index];

        delete [] temp;
    }

    void setSales(Sales & s)
    {
        using std::cout, std::endl, std::cin;
        double total = 0;
        double * temp = new double [QUARTERS];
        for (int i = 0; i < QUARTERS; i++)
        {
            cout << "Please input " << i << ". sales: ";
            cin >> s.sales[i];
            while (!cin)
            {
                cin.clear();
                while (cin.get() != '\n')
                    ;
                cout << "Wrong input. Please input " << i << ". sales: ";
                cin >> s.sales[i];
            }
            temp[i] = s.sales[i];
            total += s.sales[i];
        }

        s.average = total / QUARTERS;
        sort_sales(temp, QUARTERS);
        s.max = temp[0];
        s.min = temp[QUARTERS - 1];

        delete [] temp;
    }

    void sort_sales(double * array, int n)
    {
        int index = n - 1;
        for (double * p1 = array; p1 < (array + index); p1++)
            for (double * p2 = p1 + 1; p2 <= (array + index); p2++)
            {
                if (*p1 < *p2)
                    std::swap(*p1,*p2);
            }
    }

    void showSales(const Sales & s)
    {
        using std::cout, std::endl, std::cin;
        cout << "All Sales: " << endl;
        for (int i = 0; i < QUARTERS; i++)
            cout << i+1 << ". " << s.sales[i] << endl;
        cout << "Average: " << s.average << endl;
        cout << "Max: " << s.max << endl;
        cout << "Min: "  << s.min << endl;
    }
}