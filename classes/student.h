#ifndef CLASS_LIBRARYS
#define CLASS_LIBRARYS
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

    bool operator<(const Student &other)
    {
        if (lastname < other.lastname)
        {
            return true;
        }

        if (lastname == other.lastname && secondlastname < other.secondlastname)
        {
            return true;
        }

        if (lastname == other.lastname && secondlastname == other.secondlastname && name < other.name)
        {
            return true;
        }

        if (lastname == other.lastname && secondlastname == other.secondlastname && name == other.name && account < other.account)
        {
            return true;
        }

        if (lastname == other.lastname && secondlastname == other.secondlastname && name == other.name && account == other.account)
        {
            return true;
        }
        return false;
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
#endif