#ifndef CLASS_LIBRARYS
#define CLASS_LIBRARYS
using namespace std;

class Student
{
private:
    string name;
    string lastname;
    int age;
    int semester;

public:
    Student() : name(""), lastname(""), age(0), semester(0) {}
    Student(string n, string l, int a, int sem) : name(n), lastname(l), age(a), semester(sem) {}

    string get_name()
    {
        return name;
    }

    string get_lastname()
    {
        return lastname;
    }

    int get_age()
    {
        return age;
    }

    int get_semester()
    {
        return semester;
    }

    bool operator<(const Student &other)
    {
        if (name < other.name)
        {
            return true;
        }

        if (name == other.name && age < other.age)
        {
            return true;
        }

        if (name == other.name && age == other.age && lastname < other.lastname)
        {
            return true;
        }

        if (name == other.name && age == other.age && lastname == other.lastname && semester < other.semester)
        {
            return true;
        }

        if (name == other.name && lastname == other.lastname && age == other.age && semester == other.semester)
        {
            return true;
        }
        return false;
    }

    bool operator==(const Student &other)
    {
        if (name == other.name && lastname == other.lastname && age == other.age && semester == other.semester)
        {
            return true;
        }
        return false;
    }
    friend ostream &operator<<(ostream &os, const Student &s)
    {
        os << s.name << s.lastname << ": (age: " << s.age << ", semester: " << s.semester << ")";
        return os;
    }

    friend istream &operator>>(istream &is, Student &s)
    {
        cout << "Enter student's name: ";
        is >> s.name;
        cout << "Enter student's lastname: ";
        is >> s.lastname;
        cout << "Enter student's age: ";
        is >> s.age;
        cout << "Enter student's semester";
        is >> s.semester;
        return is;
    }
};
#endif