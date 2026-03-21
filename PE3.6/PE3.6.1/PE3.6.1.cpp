#include <iostream>
using namespace std;

int main(void){
    int foot{};
    
    cout << "Please enter your height in feet:___\b\b\b";
    cin >> foot;
    cin.get();
    cout << "your height is "
    << int(foot / 12.0)
    << "inches and "
    << foot % 12 // 除余运算符号两边一定要是同类型
    << "feet.";


    return 0;
}