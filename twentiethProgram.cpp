//Program to code a mesage using queues and stacks
//Example input: "Bond, James Bond" to "BnodJo s, dBneam"
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

void reverseWords(string& s){
    queue<char> q;
    stack<char> st;
    for (char c : s){
        if (isalpha(c)){
            q.push(c);
        }
    }
    for (char c : s){
        if (isalpha(c)){
            st.push(q.front());
            q.pop();
        }
    }
    for (int i = 0; i < s.size(); i++){
        if (isalpha(s[i])){
            s[i] = st.top();
            st.pop();
        }
    }
}

int main(){

    reverseWords("Bond, James Bond");

}