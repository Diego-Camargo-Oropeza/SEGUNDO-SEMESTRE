#include <iostream>
#include <stdlib.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

class lists
{
private:
    int *lists_list;
    int n;

public:
    lists(int size, int values[])
    {
        lists_list = new int[size];
        n = size;
        // cout << "Enter data: " << endl;
        for (int i = 0; i < n; i++)
        {
            lists_list[i] = values[i];
        }
    }
    ~lists()
    {
        delete[] lists_list;
        cout << "Destroying object \n";
    }

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << lists_list[i] << " ";
        }
        cout << '\n';
    }

    void swap_sort()
    {
        cout << "Sorting by swapping: \n";
        for (int i = 0; i < (n - 1); i++)
        {
            // cout << i + 1 << ". iteration: \n";
            for (int j = (i + 1); j < n; j++)
            {
                if (lists_list[i] > lists_list[j])
                {
                    swap(lists_list[i], lists_list[j]);
                }
            }
            // print();
        }
    }
    void select_sort()
    {
        cout << "Sorting by selecting: \n";
        for (int i = 0; i < (n - 1); i++)
        {
            // cout << i + 1 << ".interation \n";
            int lowest = lists_list[i];
            int pos = i;
            for (int j = (i + 1); j < n; j++)
            {
                if (lists_list[j] < lowest)
                {
                    lowest = lists_list[j];
                    pos = j;
                }
            }
            lists_list[pos] = lists_list[i];
            lists_list[i] = lowest;
            // print();
        }
    }

    void insert_sort()
    {
        cout << "Sort  by inserting :\n";
        for (int i = 1; i < n; i++)
        {
            // cout << i << ". iteration\n";
            int j = i;
            int temp = lists_list[j];
            while (j > 0 && lists_list[j - 1] > temp)
            {
                lists_list[j] = lists_list[j - 1];
                j--;
            }
            lists_list[j] = temp;
            // print();
        }
    }
    void bubble_sort()
    {
        cout << "Bubble sorting: \n";
        for (int i = 0; i < (n - 1); i++)
        {
            // cout << i + 1 << ".Iteration\n";
            for (int j = 0; j < (n - 1) - i; j++)
            {
                if (lists_list[j] > lists_list[j + 1])
                {
                    swap(lists_list[i], lists_list[j]);
                }
            }
            // print();
        }
    }
};

int main()
{
    // cout << "Enter list's size: ";
    // cin >> n;
    const int N = 500;
    int *original = new int[N];
    for (int i = 0; i < N; ++i)
    {
        original[i] = (rand() % N) + 1;
    }
    lists a(N, original);
    lists b(N, original);
    lists c(N, original);
    lists d(N, original);

    auto start = high_resolution_clock::now();
    a.swap_sort();
    auto end = high_resolution_clock::now();
    milliseconds duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << " miliseconds.";

    start = high_resolution_clock::now();
    b.select_sort();
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << " miliseconds.";

    c.insert_sort();
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << " miliseconds.";

    d.bubble_sort();
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << " miliseconds.";

    // a.swap_sort();
    // a.select_sort();
    // a.insert_sort();
    // a.bubble_sort();
    return 0;
}
