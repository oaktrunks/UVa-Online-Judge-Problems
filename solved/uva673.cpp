//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Paentheses Balance : 673 : oaktrunks

//Data structure required : stacks

//Tricks of the trade : push to stack if left parenthesis
//						if right parenthesis, check if it's same type
//						of parenthesis as top of stack, else not correct

/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	int lines;
	char tempChar;
	string line;

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> lines;
	cin.ignore();
	for (int i = 0; i < lines; i++){
		bool correct = true;
        stack<char> parentheses;
		getline(cin, line);
		for (int i = 0; i < line.length(); i++){
			tempChar = line[i];
			if (tempChar == '[' || tempChar == '('){
				parentheses.push(tempChar);
			}
			else if (parentheses.empty()){
				correct = false;
				break;
			}
			else if (tempChar == ']'){
				if (parentheses.top() == '('){
					correct = false;
					break;
				}
				else
					parentheses.pop();
			}
			else if( tempChar == ')'){
				if (parentheses.top() == '['){
					correct = false;
					break;
				}
				else
					parentheses.pop();
			}
		}
		if (correct && parentheses.empty()){
			cout << "Yes\n";
		}
		else
			cout << "No\n";
	}
	return 0;
}