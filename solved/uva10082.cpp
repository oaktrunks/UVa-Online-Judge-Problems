//////////////////////////////////////////////////////////////////////

//Daniel Tomei : WERTYU : 10082 : oaktrunks

//Data structure required : strings

//Tricks of the trade : ascii indexing

/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int main(){

	string shifted = " 1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";
	string original =" `1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";
	char conversion[256];
	string input;

	//Creating ascii indexed array to convert characters
	for (int i = 0; i < shifted.length(); i++){
		conversion[shifted[i]] = original[i];
	}

	//converting and outputting new string
	while (getline(cin, input)){
		for (int i = 0; i < input.length(); i++){
			/*if (input[i] == ' ') changed space to map to space
				continue;*/
			input[i] = conversion[input[i]];
		}

		cout << input << "\n";
	}

	return 0;
}