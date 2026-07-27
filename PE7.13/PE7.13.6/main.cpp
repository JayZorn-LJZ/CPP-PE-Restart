#include <iostream>

using namespace std;

int fill_array(double *, int);
void show_array(double *, int);
void reverse_array(double *, int);

int main(void)
{
    const int size = 10;
    double array[10] {};
    int count = fill_array(array, size);

    cout << "total input " << count << "numbers" << endl;
    show_array(array, count);
    reverse_array(array, size);
    show_array(array, size);

    return 0;
}

int fill_array(double * array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Please input a number(left " << size << " ): ";
        cin >> array[i];
        if (!cin)
        {
            return i + 1;
        }
    }
    return size;
}

void show_array(double * array, int size)
{
    for (int i = 0; i < size; i++)
        cout << i << " : " << array[i] << endl;
}

void reverse_array(double * array, int size)
{
    for (int i = 9; i > 5; i--)
    {   
        double temp = array[i];
        array[i] = array[9 - i];
        array[9 - i] = temp;
    }    
}