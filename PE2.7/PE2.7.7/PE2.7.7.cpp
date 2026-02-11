#include <iostream>

using namespace std;

void show_time(int, int);

int main(void){
    int hours = 0;
    int minutes = 0;

    cout << "Enter the number of hours: ";
    cin >> hours;
    cout << "Enter the number of minutes: ";
    cin >> minutes;

    show_time(hours, minutes);

    return 0;
}

void show_time(int h, int m){
    cout << "Time: " << h << ":" << m;
}