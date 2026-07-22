#include <iostream>

using namespace std;
const int ArSize = 12;
const int Years = 3;

int main(void)
{
    const char * months[ArSize] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int x[3][ArSize] {};
    int total {};
    for (int y = 0; y < Years; y++)
    {
        for (int i{}, temp; i < ArSize; i++)
        {
            cout << "Please input " << y+1 << " year " << months[i] << " xiaoshouer: ";
            cin >> temp;
            total += temp;
            x[y][i] = temp;
        }
    }
    cout << "The total is " << total << endl;
    for (int y = 0; y < Years; y++)
        for (int i = 0; i < ArSize; i++)
        {
            cout<< y+1 << " year " << months[i] << " is " << x[y][i] << endl;
        }

    return 0;
}