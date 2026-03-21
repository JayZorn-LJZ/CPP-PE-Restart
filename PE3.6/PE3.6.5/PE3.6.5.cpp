#include <iostream>
using namespace std;

int main(void){
    long long world_population{};
    long long country_population{};

    cout << "Enter the world's population:_____________\b\b\b\b\b\b\b\b\b\b\b\b\b";
    cin >> world_population;
    cout << "Enter the country_population:_____________\b\b\b\b\b\b\b\b\b\b\b\b\b";
    cin >> country_population;

    cout << "The population of the country is " 
    << float(country_population) / float(world_population) // 除号的作用在整形和浮点型两者上有不同的作用。前者整除取整，后者则是除尽为止
    << "% of the world population.";

    return 0;
}