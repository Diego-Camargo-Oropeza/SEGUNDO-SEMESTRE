#include <iostream>
#include <list>
#include <tuple>
using namespace std;

class Student
{
private:
    string name;
    string lastname;
    string secondlastname;
    int account;

public:
    Student()
    {
        name = "";
        lastname = "";
        secondlastname = "";
        account = 0;
    }
    Student(string n, string l, string s, int a)
    {
        this->name = n;
        this->lastname = l;
        this->secondlastname = s;
        this->account = a;
    }

    void read()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter Last Name: ";
        cin >> lastname;
        cout << "Enter Second Last Name: ";
        cin >> secondlastname;
        cout << "Enter Account Number: ";
        cin >> account;
    }

    void print()
    {
        cout << "Student: " << name << " " << lastname << " " << secondlastname << endl;
        cout << "Account number: " << account << endl;
    }

    bool operator<(const Student &other)
    {
        return tie(lastname, secondlastname, name, account) < tie(other.lastname, other.secondlastname, other.name, other.account);
    }

    // Overriding equality operator is necessary if we want to keep the search option working
    bool operator==(const Student &other)
    {
        if (lastname == other.lastname && secondlastname == other.secondlastname && name == other.name && account == other.account)
        {
            return true;
        }
        return false;
    }

    friend ostream &operator<<(ostream &os, const Student &s)
    {
        os << s.name << " " << s.lastname << " " << s.secondlastname << ": (account number: " << s.account << ")";
        return os;
    }

    friend istream &operator>>(istream &is, Student &s)
    {
        cout << "Enter student's name: ";
        is >> s.name;
        cout << "Enter student's lastname: ";
        is >> s.lastname;
        cout << "Enter student's second lastname: ";
        is >> s.secondlastname;
        cout << "Enter student's account number: ";
        is >> s.account;
        cout << endl;
        return is;
    }
};
int main()
{
    list<int> intList;
    list<int>::iterator itx;

    cout << "Integer list\n";
    intList.push_front(1);
    intList.push_front(2);
    intList.push_front(3);
    intList.push_back(4);
    cout << "List size: " << intList.size() << " elements" << endl;

    for (itx = intList.begin(); itx != intList.end(); itx++)
    {
        cout << *itx << " ";
    }

    cout << endl;

    cout << "Sorting... " << endl;
    intList.sort();
    for (itx = intList.begin(); itx != intList.end(); itx++)
    {
        cout << *itx << " ";
    }

    cout << endl;

    int c = 1;
    while (!intList.empty())
    {
        cout << "Deleting element no. " << c << endl;
        intList.pop_back();
        c++;
    }

    list<string> names;
    list<string>::iterator nameIt;
    names.push_front("Pedro");
    names.push_front("Pablo");
    names.push_front("Joaquin");
    names.push_front("Francisco");
    names.push_back("angel");

    for (nameIt = names.begin(); nameIt != names.end(); nameIt++)
    {
        cout << *nameIt << " ";
    }

    cout << endl;

    names.sort();

    for (nameIt = names.begin(); nameIt != names.end(); nameIt++)
    {
        cout << *nameIt << " ";
    }

    cout << endl;

    c = 1;

    while (!names.empty())
    {
        cout << "Deleting element no. " << c << endl;
        names.pop_front();
        c++;
    }

    list<Student> studentL;

    cout << "Enter student data: \n";

    for (int i = 0; i < 3; i++)
    {
        Student newS;
        newS.read();
        studentL.push_back(newS);
    }

    for (Student s : studentL)
    {
        s.print();
    }

    cout << "Sorting: \n";

    studentL.sort();

    for (Student s : studentL)
    {
        s.print();
    }

    return 0;
}