#include <iostream>
using namespace std;

int main(void){
    float ranliao;
    float licheng;

    cout << "please enter your ranliao and licheng\n";
    cout << "ranliao:______\b\b\b\b\b\b";
    cin >> ranliao;
    cout << "licheng:______\b\b\b\b\b\b";
    cin >> licheng;

    cout << (ranliao / licheng) * 100 << endl;
    
    ranliao *= 3.785;
    licheng = (licheng / 100) * 62.14;

    cout << ranliao / licheng << endl;
}