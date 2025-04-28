#include <iostream>
using namespace std;
struct date
{
    unsigned day;
    unsigned month;
    unsigned year;
};

int main()
{
    date f;
    cout << "enter today's date";
    cout << "\nday: \n";
    cin >> f.day;
    cout << "month: \n";
    cin >> f.month;
    cout << "year: \n";
    cin >> f.year;

    cout << "Today's " << f.day << "/" << f.month << "/" << f.year;
}