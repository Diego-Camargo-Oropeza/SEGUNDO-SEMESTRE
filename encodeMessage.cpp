#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;\

bool isVowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

string transformStep1(string input) {
    string output;
    stack<char> S;
    
    for (char c : input) {
        if (isVowel(c) || c == ' ') {
            while (!S.empty()) {
                output.push_back(S.top());
                S.pop();
            }
            output.push_back(c);
        } else {
            S.push(c);
        }
    }
    while (!S.empty()) {
        output.push_back(S.top());
        S.pop();
    }
    
    return output;
}

string interleaveEnds(string Y) {
    int n = Y.size();
    queue<char> Q;
    int i = 0, j = n - 1;
    while (i <= j) {
        Q.push(Y[i]);
        if (i != j)
            Q.push(Y[j]);
        i++;
        j--;
    }
    
    string Z;
    while (!Q.empty()) {
        Z.push_back(Q.front());
        Q.pop();
    }
    return Z;
}

string codeMessage(string X) {
    string Y = transformStep1(X);
    string Z = interleaveEnds(Y);
    return Z;
}

string reverseInterleaveEnds(string Z) {
    int n = Z.size();
    string Y(n, ' ');
    int left = 0, right = n - 1;
    int index = 0;
    while (left <= right && index < n) {
        Y[left] = Z[index++];
        if (left != right && index < n) {
            Y[right] = Z[index++];
        }
        left++;
        right--;
    }
    return Y;
}

string reverseTransformStep1(string Y) {
    return transformStep1(Y);
}

string decodeMessage(string Z) {
    string Y = reverseInterleaveEnds(Z);
    string X = reverseTransformStep1(Y);
    return X;
}

int main() {
    int op;
    string message;
    
    cout << "1. Code message\n";
    cout << "2. Decode message\n";
    cout << "Enter op: ";
    cin >> op;
    cin.ignore(); 
    
    if (op == 1) {
        cout << "Enter the message to Code:\n";
        getline(cin, message);
        string coded = codeMessage(message);
        cout << "Coded message:" << coded << "\n";
    } else if (op == 2) {
        cout << "Enter the message to decode:\n";
        getline(cin, message);
        string decoded = decodeMessage(message);
        cout << "Decoded message:\n" << decoded << "\n";
    }

    return 0;
}
