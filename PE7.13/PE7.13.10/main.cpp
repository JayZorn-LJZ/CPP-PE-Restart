#include <iostream>

using namespace std;

double calculate(double, double, double (*)(double, double));
double add(double, double);

int main(void)
{
    cout << calculate(10.4, 2.5, add);
    return 0;
}

double calculate(double x, double y, double (*func)(double, double))
{
    return add(x, y);
}

double add(double x, double y)
{
    return x + y;
}