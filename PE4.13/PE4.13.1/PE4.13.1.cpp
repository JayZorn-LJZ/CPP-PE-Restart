#include <iostream>
#include <string>
using namespace std;

int main(void){
    // string str1{};
    // char name[20]{};
    // char temp[40]{};

    // cout << "Please input your name:";
    // // getline(cin, str1);
    // // cout << str1;

    // cin.getline(name, 20);
    // cout << name;

    string fname{};
    string lname{};
    char letter_grade{};
    int age{};

    cout << "what is your first name?";
    getline(cin, fname);
    cout << "what is your last name?";
    getline(cin, lname);

    cout << "what letter grade do you deserve?";
    letter_grade = cin.get();
    cin.get();

    cout << "what is your age?";
    cin >> age;
    
    cout << "Name:"
    << lname
    << ", "
    << fname
    << endl;

    cout << "Grade:"
    << letter_grade
    << endl;

    cout << "Age:"
    << age
    << endl;

    return 0;
}