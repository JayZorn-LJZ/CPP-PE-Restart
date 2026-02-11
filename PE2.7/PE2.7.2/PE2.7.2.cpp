#include <iostream>

int main(void){
    using namespace std;

    int distance{};
    cout << "Input your distance(unit of long):";
    cin >> distance;
    cout << "\nyour distance are " << distance * 200 << " yrads.";

    return 0;
}