#ifndef CLASS_LIBRARYS
#define CLASS_LIBRARYS
using namespace std;

class Student
{
private:
    string name;
    int age;
    int semester;

public:
    Student() : name(""), age(0), semester(0) {}
    Student(string n, int a, int sem) : name(n), age(a), semester(sem) {}
    string get_name()
    {
        return name;
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
        if (name > other.name)
        {
            return true;
        }

        if (name == other.name && age > other.age)
        {
            return true;
        }

        if (name == other.name && age == other.age && semester > other.semester)
        {
            return true;
        }
        return false;
    }
    friend ostream &operator<<(ostream &os, const Student &s)
    {
        os << s.name << ": (age: " << s.age << ", semester: " << s.semester << ")";
        return os;
    }
};
#endif