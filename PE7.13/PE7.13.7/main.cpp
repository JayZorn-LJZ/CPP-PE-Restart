#include <iostream>
const int Max = 5;
int fill_array(double *, double *);
void show_array(const double *, const double *);
void revalue(double, double *, double *);

int main()
{
    using namespace std;
    double properties[Max];

    int size = fill_array(properties, properties + Max);
    show_array(properties, properties + size);
    if (size > 0)
    {
        cout << "Enter revaluation facfor: ";
        double factor;
        while (!(cin >> factor))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, properties + size);
        show_array(properties, properties + size);
    }
    cout << "Done.\n";
    cin.get();
    return 0;
}

int fill_array(double * s, double * end)
{
    using namespace std;
    double temp;
    int count = 0;
    for (double * i = s; i < end; i++, count++)
    {
        cout << "Enter value #" << (count + 1) << ": ";
        cin >> temp;
        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input process terminated.\n";
            break;
        }
        else if (temp < 0)
            break;
        *i = temp;
    }
    return count;
}

void show_array(const double * s, const double * e)
{
    using namespace std;
    int count = 0;
    for (const double * i = s; i < e; i++, count++)
    {
        cout << "Property #" << (count + 1) << ": $";
        cout << *i << endl;
    }
}

void revalue(double r, double * s, double * e)
{
    for (double * i = s; i <= e; i++)
        *i *= r;
}