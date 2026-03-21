#include <iostream>
using namespace std;

int main(void)
{
    int feet{};
    int inches{};
    int height{}; // height in meters
    float weight{};
    float bmi{};

    cout << "Please enter your height in feet and inches as integers.\n";
    cout << "Feet:___\b\b\b";
    cin >> feet;
    cout << "Inches:___\b\b\b";
    cin >> inches;

    cout << "Please enter your weight in pounds:___\b\b\b";
    cin >> weight;

    height = (feet * 12 + inches) * 0.0254; // Convert to meters
    weight *= 0.453592; // Convert to kilograms

    bmi = weight / (height * height); // Calculate BMI

    cout << "Your BMI is: " << bmi;

    return 0;
}