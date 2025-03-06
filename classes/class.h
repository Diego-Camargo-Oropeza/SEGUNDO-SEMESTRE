#ifndef CLASS_LIBRARY
#define CLASS_LIBRARY
using namespace std;

template <typename T>
class linear_list
{
private:
    T *linear_l;
    int size;
    int n;

public:
    linear_list(int s)
    {
        linear_l = new T[s];
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

    void push_back(T item)
    {
        if (n < size)
        {
            linear_l[n++] = item;
        }
        else
        {
            cout << "List's full, cannot add more items\n";
        }
    }
    void search_element()
    {
        if (n > 0)
        {
            T el;
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

    void select_sort()
    {
        cout << "Sorting by selecting: \n";
        for (int i = 0; i < (n - 1); i++)
        {
            cout << i + 1 << ".interation \n";
            T lowest = linear_l[i];
            int pos = i;
            for (int j = (i + 1); j < n; j++)
            {
                if (linear_l[j] < lowest)
                {
                    lowest = linear_l[j];
                    pos = j;
                }
            }
            linear_l[pos] = linear_l[i];
            linear_l[i] = lowest;
            print();
        }
    }
};

#endif
