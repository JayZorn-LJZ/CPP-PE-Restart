#include <iostream>
#include <string>
#include <array>

using namespace std;

int main(void){
    array<float, 3> a1;

    cout << "Please input your first mark:";
    cin >> a1[0];
    cout << "Please input your next maek:";
    cin >> a1[1];
    cout << "Please input your last mark:";
    cin >> a1[2];

    cout << a1.at(0) << endl
    << a1.at(1) << endl
    << a1.at(2) << endl;

    cout << a1.size() << endl;
    cout << (a1.at(0) + a1.at(1) + a1.at(2)) / a1.size();

    return 0;

}