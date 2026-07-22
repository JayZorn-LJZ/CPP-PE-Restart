#include <iostream>

using namespace std;
const int ArSize = 12;

int main(void)
{
    const char * months[ArSize] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int x[ArSize] {};
    int total {};
    for (int i{}, temp; i < ArSize; i++)
    {
        cout << "Please input " << months[i] << " xiaoshouer: ";
        cin >> temp;
        total += temp;
        x[i] = temp;
    }
    cout << "The total is " << total << endl;
    for (int i = 0; i < ArSize; i++)
    {
        cout << months[i] << " is " << x[i] << endl;
    }

    return 0;
}