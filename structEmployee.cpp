#include <iostream>
using namespace std;

const int n = 5;

struct employee
{
    char name[50];
    char rfc[18];
    double salary;
};

int main()
{
    employee employee[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Employee no" << i + 1 << ". name: " << endl;
        cin.getline(employee[i].name, 50, '\n');
        cout << "Employee no" << i + 1 << ". rfc: " << endl;
        cin.getline(employee[i].rfc, 18, '\n');
        cout << "Employee no" << i + 1 << ". salary: " << endl;
        cin >> employee[i].salary;
        cin.ignore();
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Employee no" << i + 1 << ". name: " << employee[i].name << endl;
        cout << "Employee no" << i + 1 << ". rfc: " << employee[i].rfc << endl;
        cout << "Employee no" << i + 1 << ". salary: " << employee[i].salary << endl;
    }

    return 0;
}