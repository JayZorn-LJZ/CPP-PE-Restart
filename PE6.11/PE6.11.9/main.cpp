#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct c {
    string name;
    double ct;
};
c * add_c(c *, const int);

int main(void)
{
    // 1. 声明结构
    // 2. 创建动态数组、缓冲数组
    // 3. 循环读取用户输入到新数组
    // 4. 释放源数组并写入到新数组中
    // 5. 显示数据
    // 6. 释放数组

    int count = 0;
    c * c_a = new c [count + 1];
    ifstream file;
    file.open("test.txt");

    while (true)
    {
        if (!(file >> c_a[count].ct))
            break;
        file.get();
        if (!getline(file, c_a[count].name))
            break;
        count++;
        c_a = add_c(c_a, count);
    }

    bool b_g = false;
    bool b = false;

    cout << "Grand Patrons: " << endl;
    for (int i = 0; i < count; i++)
    {
        if (c_a[i].ct > 10000)
        {   
            cout << i << ". " << c_a[i].name << " : " << c_a[i].ct << endl;
            b_g = true;
        }
    }

    cout << "Patrons: " << endl;
    for (int i = 0; i < count; i++)
    {
        if (c_a[i].ct <= 10000)
        {   
            cout << i << ". " << c_a[i].name << " : " << c_a[i].ct << endl;
            b = true;
        }
    }

    if (!b_g)
        cout << "None Grand Pratrons.";
    else if (!b)
        cout << "None Pratrons.";
    else
        ;
    
    file.close();
    delete [] c_a;
    return 0;
}

c * add_c(c * raw_a, const int a_size)
{
    c * new_a = new c [a_size + 1];
    for (int i = 0; i < a_size; i++)
    {
        new_a[i] = raw_a[i];
    }
    delete [] raw_a;
    return new_a;
}