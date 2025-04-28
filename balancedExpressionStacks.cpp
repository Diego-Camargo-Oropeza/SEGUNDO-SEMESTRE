#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string expresion){
	stack<char> indiv;
	for(char c: expresion){
		if(c=='[' || c=='(' || c=='{'){
			indiv.push(c);
		}else if(c==']' || c==')' || c=='}'){
			if(indiv.empty()) return false;

		char top = indiv.top();
		indiv.pop();
		if(c==')' && top != '(' ||
		   c==']' && top != '[' ||
		   c=='}' && top != '{') {
		   return false;
		   }
		}
	}
	return indiv.empty();
}

int main(){
    cout << "Enter expression";
	string exp;
	cin >> exp;

	if(isBalanced(exp)){
		cout << "Balanced expression\n";
	}else{
		cout << "Unbalanced expression\n";
	}
	

    return 0;
}
