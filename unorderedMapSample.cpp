#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, string> students;
    unordered_map<string, string> contact_book;
    students[12345] = "Juan Perez";
    students[67890] = "Maria Gonzalez";
    students[11223] = "Carlos Sanchez";

    cout << "Hash Table of Students:" << endl;

    for (auto pair : students)
    {
        cout << "ID: " << pair.first << ", Name: " << pair.second << endl;
    }

    int id;
    cout << "Enter student ID to search: ";
    cin >> id;

    if (students.find(id) != students.end())
    {
        cout << "Student found: " << students[id] << endl;
    }
    else
    {
        cout << "Student not found." << endl;
    }

    cout << "Enter student ID to delete: ";
    cin >> id;

    if (students.erase(id))
    {
        cout << "Student with ID " << id << " deleted." << endl;
    }
    else
    {
        cout << "Student  with ID " << id << "not found." << endl;
    }

    cout << "Updated Hash Table of Students:" << endl;
    for (auto pair : students)
    {
        cout << "ID: " << pair.first << ", Name: " << pair.second << endl;
    }

    // self example:

    contact_book["7713553077"] = "Diego Camargo";
    contact_book["7713553078"] = "Diego Camargo"; // same name, different number
    contact_book["7711245695"] = "Virgilio Camargo";
    contact_book["7710932399"] = "Erick Fernando";
    contact_book["7717722901"] = "Maria Ines";

    cout << "Displaying Contact Book:" << endl;
    for (auto pair : contact_book)
    {
        cout << "Number: " << pair.first << ", Name: " << pair.second << endl;
    }
    cout << "Enter number to search: ";
    string number;
    cin >> number;
    if (contact_book.find(number) != contact_book.end())
    {
        cout << "Contact found: " << contact_book[number] << endl;
    }
    else
    {
        cout << "Contact not found." << endl;
    }

    return 0;
}