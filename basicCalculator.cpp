#include <iostream>
#include <math.h>
using namespace std;

double operation(int, int, char);

int main()
{
    int a, b;
    char c;
    cout << "Please enter the type of operation that you need: \n";
    cin.get(c);
    cout << "Please enter the first number \n";
    cin >> a;
    cout << "Please enter the second number \n";
    cin >> b;
    cout << "The answer is " << operation(a, b, c) << endl;
}

double operation(int a, int b, char c)
{
    switch (c)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        if(b==0){
            return INFINITY;
        }
        return (double) a / b;
        break;
    default:
        cout << "No valid operation has been chose so...";
        break;
    }
    return 0;
}