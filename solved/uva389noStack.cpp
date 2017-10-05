//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Basically Speaking : 389 : oaktrunks

//Data structure required : 

//Tricks of the trade : My first solution used a stack to output my calculations
//						backwards. This second solution uses a string
//						and uses an index to fill it up backwards.
//						runtime of stack solution = 0.050
//						runtime of string solution = 0.020

/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	string input;
	int baseFrom, baseTo, numBase10, temp;
	string answer;
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> input >> baseFrom >> baseTo) {
		//Converting to base 10
		numBase10 = 0;
		for (int i = 0; i < input.length() - 1; i++) {
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
		if (baseTo == 10) {
			//check if output longer than 7 numbers
			numBase10 >= 10000000 ?
				cout << "  ERROR\n" :
				cout << right << setw(7) << numBase10 << '\n';
			continue;
		}

		//Convert to final base
		answer = "       "; //seven spaces
		int j = 6; //indexing string backwards
		bool error = false;
		while (numBase10 > 0) {
			temp = numBase10 % baseTo;
			temp > 9 ? temp += 55 : temp += 48;

			//check if answer is longer than 7 numbers
			if (j < 0) {
				cout << "  ERROR\n";
				error = true;
				break;
			}
			answer[j] = temp;
			j--;
			
			numBase10 /= baseTo;
		}

		//output answer
		if(!error)
			cout << answer << '\n';
	}

	return 0;
}