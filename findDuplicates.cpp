#include <iostream>
using namespace std;

bool has_duplicates(int *, int);
int main()
{
    int size = 6;
    int array[size];
    for (int i = 0; i < 6; i++)
    {
        cout << "Enter " << i + 1 << ". value -> ";
        cin >> array[i];
        cout << endl;
    }
    // dec = has_duplicates(array, size);
    if (has_duplicates(array, size))
    {
        cout << "Matches have been found";
    }
    else
    {
        cout << "No matches found";
    }
}

bool has_duplicates(int array[6], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
            if (array[i] == array[j])
            {
                return true;
            }
    }
    return false;
}

// UNEFFICIENT SOL...
//  bool has_duplicates(int array[6], int size)
//  {
//      for (int i = 0; i < size; i++)
//      {
//          for (int j = 0; j < size; j++)
//              if (i != j)
//              {
//                  if (array[i] == array[j])
//                  {
//                      return true;
//                  }
//                  else
//                  {
//                      return false;
//                  }
//              }
//      }
//  }