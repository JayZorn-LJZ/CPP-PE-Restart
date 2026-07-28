#include <iostream>

using namespace std;

template <typename T> T max5(T *, int n = 5);

int main(void)
{
    double array[5] {1.0, 3.1, 4.9, 5.4, 6.1};
    int array_i[5] {2,3,656,34,43};

    cout << max5(array) << endl;
    cout << max5(array_i) << endl;

    return 0;
}

template <typename T> T max5(T * p, int n)
{
    T max = 0;
    for (int i = 0; i < n; i++)
    {
        max = max < p[i] ? p[i] : max;
    }

    return max;
}