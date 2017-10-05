//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Splitting numbers : 11933 : oaktrunks

//Data structure required : bitset

//Tricks of the trade : iterating through bitset and using a boolean
//							to decide how to split the ones
//   didn't use bitmasking and shifting; runtime was already 0.0
//   changing to shifts instead of to_ulong() would be more efficient
//   masking instead of bitsets would be more efficient too
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <bitset>

using namespace std;

int main() {

	int input;
	cin >> input;
	while (input > 0) {
		bitset<32> number(input);
		bitset<32> partA;
		bitset<32> partB;
		bool A = true;
		for (int i = 0; i < 32; i++) {
			if (number[i]) {
				if (A)
					partA[i] = true;
				else
					partB[i] = true;

				A = !A;
				
			}
		}
		cout << partA.to_ulong() << " " << partB.to_ulong() << "\n";

		cin >> input;
	}

	return 0;
}