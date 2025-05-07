#include <iostream>
#include <fstream>
using namespace std;

class person
{
private:
    char name[50];
    char sex[30];
    int age;

public:
    void print()
    {
        cout << "\nThe name is: " << name;
        cout << "\nSex: " << sex;
        cout << "\nAged: " << age;
    }

    void read()
    {
        cout << "Enter name: \n";
        cin.getline(name, 50);
        cin.ignore();
        cout << "Enter sex\n";
        cin.getline(sex, 30);
        cin.ignore();
        cout << "Enter age: \n";
        cin >> age;
    }
};

void add_register()
{
    ofstream file;
    file.open("data.dat", ios::binary | ios::app);
    if (file.fail())
    {
        cout << "Error while trying to open the file\n";
        return;
    }
    person p;
    p.read();
    file.write(reinterpret_cast<char *>(&p), sizeof(person));
    file.close();
}

void read_register()
{
    ifstream file;
    file.open("data.dat", ios::binary | ios::in);
    if (file.fail())
    {
        cout << "Error while trying to open the file\n";
        return;
    }

    person p;
    file.read(reinterpret_cast<char *>(&p), sizeof(person));
    p.print();
    file.close();
}

void read_registers()
{

    ifstream file;
    file.open("data.dat", ios::binary | ios::in);
    if (file.fail())
    {
        cout << "Error while trying to open the file\n";
        return;
    }

    person p;

    while (file.read(reinterpret_cast<char *>(&p), sizeof(person)))
        p.print();
    file.close();
}

int main()
{
    add_register();
    read_register();
    read_registers();
}