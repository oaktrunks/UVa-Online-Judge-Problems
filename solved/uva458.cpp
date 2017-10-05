//////////////////////////////////////////////////////////////////////

//Daniel Tomei : The Decoder : 458 : oaktrunks

//Data structure required : strings

//Tricks of the trade : output every character minus 7 (ascii)

/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line;
	ios_base::sync_with_stdio(false); cin.tie(0); //secret optimization tricks
	while (getline(cin, line))
	{
		//decode is -7 to ascii value
		//for some reason modifying the string
		// and printing string as a whole is faster
		// than looping and printing each char - 7
		for (int i = 0; i < line.length(); i++){
			line[i] -= 7;
		}
		cout << line << "\n";
	}

	return 0;
}