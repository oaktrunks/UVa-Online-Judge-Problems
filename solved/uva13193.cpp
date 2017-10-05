//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Rotations : 13193 : oaktrunks

//Data structure required : 

//Tricks of the trade : Using bitmasking so I can be faster than
//						the people using bitsets.

/////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	unsigned int t, n; //test cases, number to test with
	cin >> t;
	for (unsigned int i = 0; i < t; i++){
		cin >> n;
		unsigned int mask = 4160749568; //five ones and 27 zeros
		bool values[32] = { false }; //array of booleans for checking duplicates
		bool duplicate = false;
		for (unsigned int j = 0; !duplicate && j <= 27; j++){ //Check 28 numbers, missing 4 from looping around edges
			values[(n & mask) >> (27 - j)] ? duplicate = true : values[(n & mask) >> (27 - j)] = true;
			mask = mask >> 1;
		}
		//Check the 4 cases we missed
		if (!duplicate){
			values[((n & 15) << 1) + ((n & 2147483648) >> 31)] ? duplicate = true : values[((n & 15) << 1) + ((n & 2147483648) >> 31)] = true;
			values[((n & 7) << 2) + ((n & 3221225472) >> 30)] ? duplicate = true : values[((n & 7) << 2) + ((n & 3221225472) >> 30)] = true;
			values[((n & 3) << 3) + ((n & 3758096384) >> 29)] ? duplicate = true : values[((n & 3) << 3) + ((n & 3758096384) >> 29)] = true;
			values[((n & 1) << 4) + ((n & 4026531840) >> 28)] ? duplicate = true : values[((n & 1) << 4) + ((n & 4026531840) >> 28)] = true;
		}

		duplicate ? cout << "no\n" : cout << "yes\n";
	}

	return 0;
}