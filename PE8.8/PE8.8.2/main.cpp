#include <iostream>
#include <cstring>

struct CandyBar {
    char name[20];
    double weight;
    int reliang;
};
void fill(CandyBar &, const char * name = "Millennium Munch", double weight = 2.85, int reliang = 350);
void show(const CandyBar &);

int main(void){
    using namespace std;

    CandyBar cb;
    fill(cb, "Hell", 3.9, 390);
    show(cb);

    fill(cb);
    show(cb);

    return 0;
}

void fill(CandyBar & cb, const char * name, double weight, int reliang) // 定义处不能写上默认参数
{
    using namespace std;
    strncpy(cb.name, name, 20);
    cb.weight = weight;
    cb.reliang = reliang;
}

void show(const CandyBar & cb)
{
    using std::cout, std::endl; // using 编译指令允许同时声明多个变量

    cout << cb.name << endl;
    cout << cb.weight << endl;
    cout << cb.reliang << endl;
}