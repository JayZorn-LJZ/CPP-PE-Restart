#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    struct inf {
        string cname;
        float zhijing;
        float weight;
    };

    inf * f1 = new inf;

    cout << "Please input your zhijing:";
    cin >> f1->zhijing;
    cin.get();
    cout << "Please input your cname:";
    getline(cin, f1->cname);
    cout << "Please input your weight:";
    cin >> f1->weight;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(3);

    cout << f1->cname << endl
    << f1->zhijing << endl
    << f1->weight << endl;

    delete f1;

    return 0;
}