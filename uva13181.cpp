//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Sleeping in Hostels : 13181 : oaktrunks

//Data structure required : string

//Tricks of the trade : Just iterating over a string and counting
//						the number of adjacent '.'s
//						Three cases: max adjacent '.'s are either at
//						the beginning of the string (before any X's)
//						or at the end of the string(no X's afterwards)
//						or the middle of the string(surrounded by two X's)
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	string line;
	int max, count; //maximun number of adjacent dots, temp int for comparing to max
	bool beforeX; //boolean to see if we haven't hit an X yet.
	while (getline(cin, line) && line != ""){
		count = 0;
		max = 0;
		beforeX = true;
		for (int i = 0; i < (int)line.length(); i++){
			if (line[i] == 'X'){ //reset count when you hit an X
				count = 0;
				beforeX = false;
			}
			else count++;
			if (i == line.length() - 1) count = count << 1; //multiply count by two
			if (count > max){
				max = count;
				if (beforeX && i + 1 < (int)line.length() && line[i + 1] == 'X'){
					max = max << 1;
				}
			}
		}
		if (!(max % 2)) cout << max/2 - 1 << '\n'; //subtract 1 if even
		else cout << max / 2 << '\n';
	}

	return 0;
}