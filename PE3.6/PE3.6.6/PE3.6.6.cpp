#include <iostream>
using namespace std;

int main(void){
    float kilometers{};
    float liters{};

    cout << "Please input your kilometers and liters\n";
    cout << "kilometers:_________\b\b\b\b\b\b\b\b\b";
    cin  >> kilometers;
    cout << "liters::_________\b\b\b\b\b\b\b\b\b";
    cin >> liters;

    cout << "each kilometers cost" << liters / kilometers << " liter";

    return 0;
}