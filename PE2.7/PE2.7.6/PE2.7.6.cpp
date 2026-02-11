#include <iostream>

double convert(double);

int main(void){
    using namespace std;

    double l_years = 0;

    cout << "Enter the number of light years: ";
    cin >> l_years;
    cout << l_years << " light years = " << convert(l_years) << " astronmical units.";

    return 0;
}

double convert(double i)
{
    return i * 63240.0;
}