#include <iostream>

using namespace std;

void fill(double *, int);
void show(const double *, int);
double average(const double *, int);

int main(void)
{
    double score[10] {};

    fill(score, 10);
    show(score, 10);
    cout << "average is :"  << average(score, 10);

    return 0;
}

void fill(double * array, int arsize)
{
    for (int i = 0; i < arsize && cin; i++)
    {
        cout << "Please input your score: ";
        cin >> array[i];
    }
}

void show(const double * array, int arsize)
{
    cout << "Your score is :";
    for (int i = 0; i < arsize; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

double average(const double * array, int arsize)
{
    double average {};
    for (int i = 0; i < arsize; i++)
        average += array[i];
    return average / arsize;
}