#include <iostream>
#include <string>

using namespace std;

int main(void){

    struct CandyBar {
        string p{};
        float weight{};
        int calorios{};
    };

    CandyBar * carray = new CandyBar[3];

    *carray = {"p1", 3.2, 890};
    *(carray+1) = {"p2", 4.5, 129};
    *(carray+2) = {"p3", 2.9, 480};

    cout << carray->p << endl
    << carray->weight << endl
    << carray->calorios << endl;

    cout << (carray+1)->p << endl
    << (carray+1)->weight << endl
    << (carray+1)->calorios << endl;

    cout << (carray+2)->p << endl
    << (carray+2)->weight << endl
    << (carray+2)->calorios << endl;

    delete [] carray;

    return 0;
}

