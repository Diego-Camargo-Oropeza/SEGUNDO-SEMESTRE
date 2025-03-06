#include <iostream>
using namespace std;

struct address
{
    char settlement[30];
    char street[30];
    int number;
};

struct person
{
    char name[30];
    address address;
};

int main()
{
    person p;
    cout << "What's your name? \n";
    cin.getline(p.name, 30, '\n');
    cout << "Please give me your address... \n";
    cout << "Enter settlement: " << endl;
    cin.getline(p.address.settlement, 30, '\n');
    cout << "Enter street: " << endl;
    cin.getline(p.address.street, 30, '\n');
    cout << "Enter number: " << endl;
    cin >> p.address.number;
    cin.ignore();
    cout << "Printing data... \n";
    cout << "Name: " << p.name << endl;
    cout << "Address details: " << endl;
    cout << "   Settlement: " << p.address.settlement << endl;
    cout << "   Street: " << p.address.street << endl;
    cout << "   Number: " << p.address.number << endl;
}