#include <iostream>

using namespace std;

int main(void)
{
    struct car {
        string producer;
        int year;
    };
    int car_num {};

    cout << "How many cars?: ";
    cin >> car_num;
    cin.get();
    car * array = new car[car_num];
    for (int i = 0; i < car_num; i++)
    {
        cout << "Please input the " << i+1 << " car's producer: ";
        getline(cin, array[i].producer);
        cout << "Please input the " << i + 1 << " car's year: ";
        cin >> array[i].year;
        cin.get();
    }
    for (int i = 0; i < car_num; i++)
    {
        cout << "The " << i + 1 << "produce by " << array[i].producer << " in " << array[i].year << " year." << endl;
    }

    delete [] array;
    return 0;
}