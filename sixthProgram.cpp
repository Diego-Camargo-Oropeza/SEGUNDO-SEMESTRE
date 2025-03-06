#include <iostream>

using namespace std;

struct student
{
    string name;
    double grade[3];
};

double findMean(student);
double findMean(double[], int);

int main()
{
    cin.clear();
    student a;
    double arr[5] = {10, 8, 7, 9, 5};
    cout << "Please enter student's name: \n";
    getline(cin, a.name);
    // cin.getline(a.name, 50, '\n');
    cout << "Please enter student grades: \n";
    for (int i = 0; i < 3; i++)
    {
        cout << "grade number " << i + 1 << ". ";
        cin >> a.grade[i];
        cout << endl;
    }

    cout << a.name << "'s" << " mean equals to: " << findMean(a);
    system("pause");
    system("cls");
    cout << "Function override: \n";
    cout << "Static's array values: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "grade " << i + 1 << ". " << arr[i];
        cout << endl;
    }
    cout << "Static's array mean: " << findMean(arr, 5) << endl;
    // cin.get();
    return 0;
}

double findMean(student a)
{

    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += a.grade[i];
    }
    return (double)sum / 3;
}

double findMean(double arr[], int a)
{
    int sum = 0;
    for (int i = 0; i < a; i++)
    {
        sum += arr[i];
    }
    return (double)sum / a;
}
