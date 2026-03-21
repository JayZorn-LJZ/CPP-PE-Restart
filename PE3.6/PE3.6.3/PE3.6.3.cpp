#include <iostream>
using namespace std;

int main(void){
    int degrees{};
    int minutes{};
    int seconds{};
    float total_degrees{};

    cout << "Enter a latitude in degrees, minutes, and seconds:\n";
    cout << "First, enter the degrees:___\b\b\b";
    cin >> degrees;
    cout << "Next, enter the minutes of arc:___\b\b\b";
    cin >> minutes;
    cout << "Finally, enter the seconds of arc:___\b\b\b";
    cin >> seconds;

    total_degrees = degrees + minutes / 60.0 + seconds / 3600.0;

    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(5);

    cout << degrees
    << " degrees, "
    << minutes
    << " minutes, and "
    << seconds
    << " seconds = "
    << total_degrees
    << " degrees.";

    return 0;
}