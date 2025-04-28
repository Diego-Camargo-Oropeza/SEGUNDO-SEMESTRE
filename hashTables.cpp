#include <bits/stdc++.h>
using namespace std;

class hashTable
{
private:
    // Number of buckets in the table
    static const int hashGroup = 10;
    // Each bucket holds a list of <key, value> pairs (separate chaining)
    list<pair<int, string>> table[hashGroup];

public:
    // Check whether the entire table is empty
    bool isEmpty() const
    {
        int sum = 0;
        // Sum the sizes of all the buckets
        for (int i = 0; i < hashGroup; i++)
        {
            sum += table[i].size();
        }
        // If sum==0, no elements anywhere
        return (sum == 0);
    }

    // Simple modulo-based hash function
    int hashFunction(int key)
    {
        return key % hashGroup;
    }

    // Insert or update a key–value pair
    void insertItem(int key, string value)
    {
        int hashValue = hashFunction(key);
        auto &cell = table[hashValue];        // reference to the chosen bucket
        bool keyExists = false;

        // Look for an existing pair with the same key
        for (auto it = cell.begin(); it != cell.end(); ++it)
        {
            if (it->first == key)
            {
                // Key found: replace its value
                keyExists = true;
                it->second = value;
                cout << "Key exists, value replaced" << endl;
                break;
            }
        }

        // If not found, append a new pair to the bucket
        if (!keyExists)
        {
            cell.emplace_back(key, value);
            cout << "Inserted key: " << key << " value: " << value << endl;
        }
    }

    // Remove the pair with the given key, if it exists
    void removeItem(int key)
    {
        int hashValue = hashFunction(key);
        auto &cell = table[hashValue];
        bool keyExists = false;

        // Find the pair in the bucket
        for (auto it = cell.begin(); it != cell.end(); ++it)
        {
            if (it->first == key)
            {
                keyExists = true;
                cell.erase(it);
                cout << "Item Removed" << endl;
                break;
            }
        }

        if (!keyExists)
        {
            cout << "Item not found" << endl;
        }
    }

    // Print out all non-empty buckets
    void printTable()
    {
        for (int i = 0; i < hashGroup; i++)
        {
            if (table[i].empty())
                continue;

            cout << "Group " << i << ": ";
            for (auto &p : table[i])
            {
                cout << "{" << p.first << ": " << p.second << "} ";
            }
            cout << endl;
        }
    }
};

int main()
{
    hashTable ht;

    // 1) Check empty at start
    if (ht.isEmpty())
        cout << "Hash table is empty" << endl;
    else
        cout << "Hash table is not empty" << endl;

    // 2) Insert a bunch of items
    ht.insertItem(222, "John");   // goes to bucket 2
    ht.insertItem(333, "Doe");    // bucket 3
    ht.insertItem(444, "Jane");   // 4
    ht.insertItem(555, "Smith");  // 5
    ht.insertItem(666, "Emily");  // 6
    ht.insertItem(777, "Michael");// 7
    ht.insertItem(888, "Sarah");  // 8
    ht.insertItem(999, "David");  // 9

    // 3) Insert duplicate key to test replacement
    ht.insertItem(222, "New John");    // key 222 already in bucket 2

    // 4) Print current state
    ht.printTable();

    // 5) Remove two items
    ht.removeItem(222);           // from bucket 2
    ht.removeItem(999);           // from bucket 9

    // 6) Final empty check
    if (ht.isEmpty())
        cout << "Hash table is empty" << endl;
    else
        cout << "Hash table is not empty" << endl;

    return 0;
}
