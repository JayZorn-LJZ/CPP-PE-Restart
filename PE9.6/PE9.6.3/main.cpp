#include <iostream>

using namespace std;

struct chaff
{
    char dross[20];
    int slag;
};
const int BUF = 80;

int main(void)
{
    // char buffer[BUF] {};
    char * buffer = new char[BUF];
    chaff * c_array = new(buffer) chaff[2];
    for (int i = 0; i < 2; i++)
    {
        cout << "Please input your dross: ";
        cin.getline(c_array[i].dross, 20);
        cout << "Please input your slag: ";
        cin >> c_array[i].slag;
        while (!cin)
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Wrong input. Please input your slag: ";
            cin >> c_array[i].slag;
        }
        while (cin.get() != '\n');
    }
    for (int i = 0; i < 2; i++)
    {
        cout << i << ". " << endl;
        cout << "dross: " << c_array[i].dross << endl;
        cout << "slag: " << c_array[i].slag << endl;
    }

    delete [] buffer;
    return 0;
}