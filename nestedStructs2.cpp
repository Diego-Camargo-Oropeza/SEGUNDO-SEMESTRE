#include <iostream>
#include <string>
using namespace std;

struct address
{
    string street;
    string settlement;
    int num;
};

struct student
{
    address add;
    string name;
    int grades[3];
};

double getMean(student &st);

int main()
{
    student st[4];

    for (int i = 0; i < 4; i++)
    {
        cout << "Enter " << i + 1 << ". student's name: ";
        cin >> st[i].name;
        cout << "\nEnter " << i + 1 << ". student's address\n";
        cout << "Settlement: ";
        cin >> st[i].add.settlement;
        cout << "Street: ";
        cin >> st[i].add.street;
        cout << "Number: ";
        cin >> st[i].add.num;
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter student's grade no. " << j + 1 << ": ";
            cin >> st[i].grades[j];
        }
        system("cls");
    }

    for (int i = 0; i < 4; i++)
    {
        cout << "Student Info...\n";
        cout << "Name: " << st[i].name << endl;
        cout << "Address: \n";
        cout << "Street: " << st[i].add.street << endl;
        cout << "Settlement: " << st[i].add.settlement << endl;
        cout << "Number: " << st[i].add.num << endl;
        cout << "Mean: " << getMean(st[i]) << endl;
    }
    return 0;
}

double getMean(student &st)
{
    double sum;
    for (int j = 0; j < 3; j++)
    {
        sum += st.grades[j];
    }
    return sum / 3.0;
}
