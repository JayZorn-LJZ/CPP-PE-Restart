#include <iostream>

int main(void){
    using namespace std;

    int age{};

    cout << "Enter your age:";
    cin >> age;
    cout << "Your age in months is " << age * 12 << ".";

    return 0;
}