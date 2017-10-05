//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Palindromes : 401 : oaktrunks

//Data structure required : vectors, strings

//Tricks of the trade : for mirror:
//						ascii indexing an array to check mirrored characters
//						
//						for palindrome:
//						just compare start of string with end of string
//						then move start up 1 and end down 1.
//						loop through the word.
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string character = "AEHIJLMOSTUVWXYZ12358";
	string reverse =   "A3HILJMO2TUVWXY51SEZ8";
	
	vector<char> mirror(91, '0');	//the char 0 (number) is a false input, so we can use it for checking
									//last accepted input is ascii index 90 (Z)
	string input;
	bool isPalindrome, isMirrored;
	int halflength, lastindex;

	for (int i = 0; i < character.length(); i++) {
		mirror[character[i]] = reverse[i];
	}

	while (cin >> input){

		isPalindrome = isMirrored = true;
		halflength = input.length() / 2;
		lastindex = input.length() - 1;

		for (int i = 0; i < halflength; i++){
			//checking if mirrored
			if (isMirrored && mirror[input[i]] != input[lastindex - i]) {
				isMirrored = false;
			}
			//checking if palindrome
			if (isPalindrome && input[i] != input[lastindex - i]) {
				isPalindrome = false;
				//break; can't break here, need to check every character for mirrored case
			}
		}

		//word length is odd, need to check middle char
		if (isMirrored && input.length() % 2) {
			//cout << "word length is odd" << endl;
			if (input[halflength] != mirror[input[halflength]])
				isMirrored = false;
		}

		//outputting answer
		if (!isPalindrome) {
			if (!isMirrored)
				cout << input << " -- is not a palindrome.\n\n";
			else
				cout << input << " -- is a mirrored string.\n\n";
		}
		else {
			if (!isMirrored)
				cout << input << " -- is a regular palindrome.\n\n";
			else
				cout << input << " -- is a mirrored palindrome.\n\n";

		}
	}
	
	return 0;
}