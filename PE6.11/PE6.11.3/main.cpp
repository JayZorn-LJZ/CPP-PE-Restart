#include <iostream>

using namespace std;

int main(void)
{
    enum {c = int('c'), p = int('p'), t = int('t'), g = int('g')};
    char input{};

    cout << "Please enter one of the following choices: \n"
    << "c) carnivore p) pianist\n"
    << "t) tree g) game\n"
    << "f\n";

    cout << "Please enter a c, p, t, or g: ";
    while (cin >> input)
    {
        switch (input)
        {
            case c:
                cout << "carnivore\n";
                continue;
            case p:
                cout << "pianist\n";
                continue;
            case t:
                cout << "tree\n";
                continue;
            case g:
                cout << "game" << endl;
                continue;
        }
        cout << "Please enter a c, p, t, or g: ";
    }

    return 0;
}