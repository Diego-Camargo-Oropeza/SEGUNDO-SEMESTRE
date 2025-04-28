#include <iostream>
using namespace std;

void swap(int&, int&);

int main()
{
    int a, b;
    cout << "Please enter 2 values, this values will be swapped \n";
    cin >> a;
    cin >> b;
    cout << "var a contains " << a << " while var b contains " << b << endl;
    swap(a, b);
    cout << "now a contains " << a << " while b now contains " << b << endl;
}

void swap(int &a, int &b)
{
    int swapi = b;
    b = a;
    a = swapi;
}
