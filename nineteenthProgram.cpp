#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{

    string phrase;
    cout << "Enter phrase/word: ";
    getline(cin, phrase);

    int size = phrase.length();

    cout << phrase << endl;

    stack<char> pal;
    queue<char> comp;

    for (int i = 0; i < size; i++)
    {
        if (isalpha(phrase[i]))
        {
            pal.push(toupper(phrase[i]));
            comp.push(toupper(phrase[i]));
        }
    }

    bool error = false;

    while (!pal.empty() && !comp.empty())
    {

        if (pal.top() != comp.front())
        {
            error = true;
            break;
        }
        pal.pop();
        comp.pop();
    }

    if (error)
    {
        cout << "Not Palindrome";
    }
    else
    {
        cout << "Palindrome";
    }
}
