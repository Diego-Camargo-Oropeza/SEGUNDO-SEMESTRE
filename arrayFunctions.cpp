#include <iostream>
using namespace std;

void readArray(int[], size_t);
void returnArray(int[], size_t);
int returnGreatest(int[], size_t);
int returnLowest(int[], size_t);
double getMean(int[], size_t);
bool isInArr(int[], size_t, int);
int main()
{
    // -------------------------------------- //
    int arr[6];
    int size;
    int val;
    int *dynamicArr;

    readArray(arr, 6);
    returnArray(arr, 6);
    cout << "The greatest is: " << returnGreatest(arr, 6) << endl;
    cout << "The lowest is: " << returnLowest(arr, 6) << endl;
    cout << "The mean equals to" << getMean(arr, 6) << endl;
    // -------------------------------------- //
    cout << "Dynamic Array: \n";
    cout << "Enter the size of the dynamic array: " << endl;
    cin >> size;
    dynamicArr = new int[size];
    readArray(dynamicArr, size);
    returnArray(dynamicArr, size);
    cout << "The greatest is: " << returnGreatest(dynamicArr, size) << endl;
    cout << "The mean equals to" << getMean(dynamicArr, size) << endl;
    cout << "The lowest is: " << returnLowest(dynamicArr, size) << endl;
    // -------------------------------------- //
    cout << "Please enter a value to be searched inside both arrays" << endl;
    cin >> val;
    cout << val << " will be searched in the first array... " << endl;
    if (isInArr(arr, 6, val))
    {
        cout << val << " has been found inside the array" << endl;
    }
    else
    {
        cout << "No matches found" << endl;
    }
    cout << val << " will be searched in the dynamic array... " << endl;
    if (isInArr(dynamicArr, size, val))
    {
        cout << val << " has been found inside the array" << endl;
    }
    else
    {
        cout << "No matches found" << endl;
    }
}

void readArray(int arr[], size_t n)
{

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". value ";
        cin >> arr[i];
        cout << endl;
    }
}

void returnArray(int arr[], size_t n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " . value is: " << arr[i];
        cout << endl;
    }
}

int returnGreatest(int arr[], size_t n)
{
    int greatest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (greatest < arr[i])
        {
            greatest = arr[i];
        }
    }
    return greatest;
}

double getMean(int arr[], size_t n)
{
    double sum = 0, grade = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return grade = sum / n;
}

int returnLowest(int arr[], size_t n)
{
    int lowest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (lowest > arr[i])
        {
            lowest = arr[i];
        }
    }
    return lowest;
}

bool isInArr(int arr[], size_t n, int a)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == a)
        {
            return true;
        }
    }
    return false;
}
