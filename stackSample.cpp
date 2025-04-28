#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{

    stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << myStack.top() << endl;
    while (!myStack.empty())
    {
        cout << "Deleting: " << myStack.top() << endl;
        myStack.pop();
    }

    queue<char> myQueue;

    myQueue.push('a');
    myQueue.push('b');
    myQueue.push('c');

    cout << myQueue.front() << endl;
    cout << myQueue.back() << endl;

    while(!myQueue.empty()){
        cout << "Deleting: " <<  myQueue.pop() << endl;
        myQueue.pop();
    }
    

    return 0;
}