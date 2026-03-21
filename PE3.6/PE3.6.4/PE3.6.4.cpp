#include <iostream>
using namespace std;

int main(void){
    long seconds{};
    int hours{};
    int minutes{};
    int days{};

    cout << "enter the number of seconds:___________\b\b\b\b\b\b\b\b\b\b\b";
    cin >> seconds;
    cin.get();

    hours = int(seconds % 86400 / 3600);
    minutes = int(seconds % 3600 / 60);
    days = seconds / 86400;

    cout << seconds
    << "seconds = "
    << days << " days, "
    << hours << " hours, and "
    << minutes << " minutes "
    << seconds % 60 << " seconds."
    ;

    return 0;
}