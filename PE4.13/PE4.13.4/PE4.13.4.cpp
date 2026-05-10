#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    struct CandyBar {
        string p{};
        float weight{};
        int calorios{};
    };

    CandyBar snack {"Mocha Munch", 2.3, 350};

    cout << snack.p << endl
    << snack.weight << endl
    << snack.calorios;

    return 0;
}