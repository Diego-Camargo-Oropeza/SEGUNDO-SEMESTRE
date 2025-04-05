#include <iostream>
#include <stack>
#include <string>
using namespace std;
 
int precedence(char c)
{

    stack<char> indiv;

    if (c == '#')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (isalpha(c))
        return 3;
    return -1;
}

int main()
{
    string expr, fix = "";
    stack<char> indv;

    cout << "Enter expression to fix: \n";
    getline(cin, expr);

    expr += '#';

    for (char c : expr)
    {
        while (!indv.empty() && precedence(indv.top()) >= precedence(c))
        {
            fix += indv.top();
            indv.pop();
        }

        indv.push(c);
    }

    cout << fix;
}