//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Basically Speaking : 389 : oaktrunks

//Data structure required : stack

//Tricks of the trade : 

/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <stack>
#include <iomanip>

using namespace std;

int main(){
	string input;
	int baseFrom, baseTo, numBase10, temp;
	stack<char> answer;
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> input >> baseFrom >> baseTo){
		//catching case where output will be 0
	/*	if (input <= "0000000"){
			cout << "      0\n";
			continue;
		}*/

		//Converting to base 10
		numBase10 = 0;
		for (int i = 0; i < input.length() - 1; i++){
			//Letters - 65
			if (input[i] >= 65)
				numBase10 = (numBase10 + input[i] - 55) * baseFrom;

			//Numbers - 48
			else
				numBase10 = (numBase10 + input[i] - 48) * baseFrom;
		}
		if (input[input.length() - 1] >= 65)
			numBase10 += input[input.length() - 1] - 55;
		else
			numBase10 += input[input.length() - 1] - 48;

		//if number is 0
		if (numBase10 == 0) {
			cout << "      0\n";
			continue;
		}

		//if base10 is already proper output
		if (baseTo == 10){
			//check if input longer than 7 numbers
			numBase10 >= 10000000? 
				cout << "  ERROR\n": 
				cout << right << setw(7) << numBase10 << '\n';
			continue;
		}

		//Convert to final base
		while (numBase10 > 0){
			temp = numBase10 % baseTo;
			temp > 9 ? temp += 55 : temp += 48;

			answer.push(temp);

			numBase10 /= baseTo;
		}
		//check stack size for ERROR
		if (answer.size() > 7){
			cout << "  ERROR\n";
			//empty stack for next iteration
			while (!answer.empty()) answer.pop(); 

			continue;
		}
		//add extra spacing for right justification
		// didn't want to use right and setw() from
		// iomanip due to output of multiple single chars
		else{
			for (int j = 7; j > answer.size() && answer.size() > 0; j--){
				cout << ' ';
			}
		}
			
		//output stack
		while (!answer.empty()){
			cout << answer.top();
			answer.pop();
		}
		cout << '\n';
	}

	return 0;
}