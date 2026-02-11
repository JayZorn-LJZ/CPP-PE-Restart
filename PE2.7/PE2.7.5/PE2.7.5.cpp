#include <iostream>

int d_convert_f(int);

int main(void){
    using namespace std;

    int d = 0;

    cout << "Please enter a Celsius value: ";
    cin >> d;
    cout << d 
    << " degress Celsius is " 
    << d_convert_f(d) 
    << " degress Fahrenheit.";

    return 0;
}

int d_convert_f(int d){
    return d * 1.8 + 32;
}