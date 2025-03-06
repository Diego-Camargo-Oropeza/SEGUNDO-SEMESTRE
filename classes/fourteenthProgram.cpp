#include <iostream>
#include <string>
#include "class.h"
#include "student.h"
using namespace std;

int main()
{
    int dec = -1;
    linear_list<string> l(5);
    linear_list<Student> s(3);

    //Manual pushback debugging matter only
    // l.push_back(Student("Diego", 50, 2));
    // l.push_back(Student("Miguel", 10, 2));
    // l.push_back(Student("Manuel", 30, 3));

    while (dec != 0)
    {
        cout << "Options:\n"
             << "1. Read all data\n"
             << "2. Insert one element\n"
             << "3. Print list\n"
             << "4. Print element at a given position\n"
             << "5. Know if an element is inside the list\n"
             << "6. Insert element on given position\n"
             << "7. Delete element on given position\n"
             << "8. Whipe list\n"
             << "9. Sort List\n"
             << "0. Exit\n"
             << "Please choose: ";
        cin >> dec;

        switch (dec)
        {
        case 1:
            cout << "Reading all data...\n";
            s.read();
            system("pause");
            system("cls");
            break;
        case 2:
            cout << "Inserting one element...\n";
            s.insert_element();
            system("pause");
            system("cls");
            break;
        case 3:
            cout << "Printing list...\n";
            s.print();
            system("pause");
            system("cls");
            break;
        case 4:
            cout << "Printing element at a given position...\n";
            s.print_element();
            system("pause");
            system("cls");
            break;
        case 5:
            cout << "Searching element...\n";
            s.search_element();
            system("pause");
            system("cls");
            break;
        case 6:
            cout << "Inserting element...\n";
            s.insert_into();
            system("pause");
            system("cls");
            break;
        case 7:
            cout << "Deleting element...\n";
            s.delete_element();
            system("pause");
            system("cls");
            break;
        case 8:
            cout << "Deleting...\n";
            s.delete_list();
            system("pause");
            system("cls");
            break;
        case 9:
            cout << "Sorting...\n";
            s.select_sort();
            system("pause");
            system("cls");
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
            system("pause");
            system("cls");
            break;
        }
    }
    return 0;
}