#include <iostream>

long double probability(unsigned numbers, unsigned picks);

int main()
{
    using namespace std;

    double total1, choices1;
    double total2, choices2;

    cout << "请输入第一组号码数量和选择数量：";
    cin >> total1 >> choices1;

    cout << "请输入第二组号码数量和选择数量：";
    cin >> total2 >> choices2;


    cout << "中奖概率为 1 / ";

    cout << probability(total1, choices1)
         *
         probability(total2, choices2);

    cout << endl;

    return 0;
}


long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;

    long double n;
    unsigned p;


    for (n = numbers, p = picks; p > 0; n--, p--)
    {
        result = result * n / p;
    }

    return result;
}