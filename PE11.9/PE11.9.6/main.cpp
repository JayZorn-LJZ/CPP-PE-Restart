#include <iostream>
#include "11.16.stonewt.h"

int main()
{
    using namespace std;
    Stonewt st_array[6] {138.0, 289.9, 28.8};
    Stonewt lowest {st_array[1]}; // 调用默认复制构造函数，因为是初始化
    Stonewt biggest {st_array[1]}; // 调用默认复制构造函数，因为是初始化
    int count {}; // 大于或等于 11 英石的数量

    for (int i = 0; i < 3; i++)
    {
        cout << "Please input pounds: ";
        cin >> st_array[i + 3];
        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Error, please input again:";
        }
    }

    for (int i = 0; i < 6; i++)
    {
        if (st_array[i] > biggest)
            biggest = st_array[i];
        if (st_array[i] < lowest)
            lowest = st_array[i];
        if (st_array[i] >= 154.0) // 将创建一个临时对象
            count++;
    }

    cout << "Biggest: " << biggest << endl;
    cout << "Lowest: " << lowest << endl;
    cout << "Count: " << count << endl;

    return 0;
}