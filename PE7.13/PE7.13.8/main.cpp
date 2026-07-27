#include <iostream>
#include <array>
#include <string>

const int Seasons = 4;
const char *Snames[20] = 
{
    "Spring", "Summer", "Fall", "Winter"
};
struct s {
    double e[Seasons] {};
} e;
void fill(s *);
void show(const s *);

int main()
{
    fill(&e);
    show(&e);
    return 0;
}

void fill(s * e)
{
    using namespace std;
    for (int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> (*e).e[i];
    }
}

void show(const s * e)
{
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << (*e).e[i] << endl;
        total += (*e).e[i];
    }
    cout << "Total Expense: $" << total << endl;
}