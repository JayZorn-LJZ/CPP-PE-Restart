#include <iostream>

using namespace std;

double compute(const double, const double);

int main(void)
{
    double x {};
    double y {};

    cout << "Please input two numbers in one line: ";
    cin >> x >> y;
    while (cin && x > 0 and y > 0)
    {
        cout << compute(x, y) << endl;
        cout << "Please input two numbers in one line: ";
        cin >> x >> y;
    }
}

double compute(const double x, const double y)
{
    return 2.0 * x * y / (x + y);
}