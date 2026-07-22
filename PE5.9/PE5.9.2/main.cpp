#include <iostream>
#include <array>

int main()
{
    using std::array;
    using std::cout;
    using std::cin;

    array<unsigned long long, 100> factorials;
    factorials[1] = factorials[0] = 1ll;
    for (int i = 2; i < 100; i++)
        factorials[i] = i * factorials[i - 1];
    for (int i = 0; i < 100; i++)
        std::cout << i << "! = " << factorials[i] << std::endl;
    return 0;
}