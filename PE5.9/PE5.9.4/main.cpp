#include <iostream>

using namespace std;

int main(void)
{
    double da {100};
    double cl {100};
    int count {};

    do
    {
        da += 10;
        cl += cl * 0.05 ;
        count ++;
        cout << count << " year: " << "Daphne -> " << da << ", Cleo -> " << cl << endl;
    } while (da > cl);

    cout << count;

    return 0;
}