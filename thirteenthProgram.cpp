#include <iostream>
using namespace std;

class linear_list
{
private:
    int *linear_l;
    int size;
    int n;

public:
    linear_list(int s)
    {
        linear_l = new int[s];
        size = s;
        n = 0;
    }

    ~linear_list()
    {
        delete[] linear_l;
        cout << "Destroying object...\n";
    }

    void read()
    {
        cout << "Please enter " << size << " data items:\n";
        for (int i = 0; i < size; i++)
        {
            cin >> linear_l[i];
        }
        n = size;
    }

    void print()
    {
        cout << "Contained data: ";
        if (n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                cout << linear_l[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "There is no data to display\n";
        }
    }

    void print_element()
    {
        if (n > 0)
        {
            int pos;
            cout << "Enter a valid position (1 to " << n << "): ";
            cin >> pos;
            if (pos > 0 && pos <= n)
            {
                cout << "Element at position " << pos << ": " << linear_l[pos - 1] << "\n";
            }
            else
            {
                cout << "Invalid position\n";
            }
        }
        else
        {
            cout << "No elements found\n";
        }
    }

    void insert_element()
    {
        if (n < size)
        {
            cout << "Enter data to insert: ";
            cin >> linear_l[n];
            n++;
        }
        else
        {
            cout << "List is full; cannot insert more elements\n";
        }
    }

    void search_element()
    {
        if (n > 0)
        {
            int el;
            bool is_in = false;
            cout << "Enter a element to search\n";
            cin >> el;
            for (int i = 0; i < n; i++)
            {
                if (linear_l[i] == el)
                {
                    is_in = true;
                    break;
                }
            }

            if (is_in)
            {
                cout << "Value found! \n";
            }
            else
            {
                cout << "No matching values found \n";
            }
        }
        else
        {
            cout << "No elements inside this list\n";
        }
    }

    void insert_into()
    {

        if (n < size)
        {
            int a;
            cout << "Please enter the position: \n";
            cin >> a;
            if (a > 0 && a <= n)
            {
                for (int i = n; i >= a; i--)
                {
                    linear_l[i] = linear_l[i - 1];
                    cout << "Enter the data: ";
                    cin >> linear_l[a - 1];
                    n++;
                }
            }
            else
            {
                cout << "Not a valid position\n";
            }
        }
    }
    void delete_element()
    {
        if (n > 0)
        {
            int a;
            cout << "Please enter the position that you want to delete :\n";
            cin >> a;
            if (a > 0 && a <= n)
            {
                for (int i = a - 1; i < n - 1; i++)
                    linear_l[i] = linear_l[i + 1];
                n--;
                cout << "Deleted data\n";
            }
            else
            {
                cout << "Non existen position\n";
            }
        }
        else
        {
            cout << "No items inside the list\n";
        }
    }
    void delete_list()
    {
        if (n > 0)
        {
            cout << "Deleted list\n";
            n = 0;
        }
        else
        {
            cout << "List already empty\n";
        }
    }
};

int main()
{
    int dec = -1;
    linear_list l(5);

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
             << "0. Exit\n"
             << "Please choose: ";
        cin >> dec;

        switch (dec)
        {
        case 1:
            cout << "Reading all data...\n";
            l.read();
            system("pause");
            system("cls");
            break;
        case 2:
            cout << "Inserting one element...\n";
            l.insert_element();
            system("pause");
            system("cls");
            break;
        case 3:
            cout << "Printing list...\n";
            l.print();
            system("pause");
            system("cls");
            break;
        case 4:
            cout << "Printing element at a given position...\n";
            l.print_element();
            system("pause");
            system("cls");
            break;
        case 5:
            cout << "Searching element...\n";
            l.search_element();
            system("pause");
            system("cls");
            break;
        case 6:
            cout << "Inserting element...\n";
            l.insert_into();
            system("pause");
            system("cls");
            break;
        case 7:
            cout << "Deleting element...\n";
            l.delete_element();
            system("pause");
            system("cls");
            break;
        case 8:
            cout << "Deleting...\n";
            l.delete_list();
            system("pause");
            system("cls");
            break;
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
