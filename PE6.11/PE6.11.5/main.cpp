#include <iostream>

using namespace std;

int main(void)
{
    // 1. 读取用户的收入
    // 2. 将用户的收入根据超额累进税率划分为4份
    // 3. 根据公式计算四份并累加进所得税变量
    // 4. 报告所得税

    double income {};
    double shuiZongHe {};
    cout << "Please input your income: ";
    while (cin >> income)
    {
        if (income < 0)
            break;
        shuiZongHe = ((income > 15000)? (10000 * 0.1) : 0) + ((income > 25000)? (20000 * 0.15) : 0) + ((income > 35000)? ((income - 35000) * 0.20) : 0);
        cout << "shuiZonghe is " << shuiZongHe << endl;
        cout << "Please input your income: ";
    }

    return 0;
}