#include <iostream>
using namespace std;

int main(void)
{
    double *array = new double [10];
    double temp {};
    double average {};
    
    for (int i = 0; i < 10; i++)
    {
        cin >> temp;
        array[i] = temp;
        average += temp;
    }

    average /= 10;
    cout << "average: " << average << endl;

    for (int i = 0; i < 10; i++)
    {
        if (array[i] > average)
            cout << array[i] << endl;
    }
    
    delete [] array;
    return 0;
}