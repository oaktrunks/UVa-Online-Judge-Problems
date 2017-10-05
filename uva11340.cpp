//////////////////////////////////////////////////////////////////////
/*
Daniel Tomei : Newspaper : 11340 : oaktrunks

Data structure required : Vectors, strings

Tricks of the trade : ascii indexing, iomanip to output 2 decimal places
*/
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); //optimization
	int tests, paidcharacters, articleLines, price;
	double totalPrice;
	char letter;
	string line;

	//formatting double output
	cout << fixed << setprecision(2);

	cin >> tests;
	for (int i = 0; i < tests; i++){
		vector<int> letterPrices(256, 0);
		totalPrice = 0;
		cin >> paidcharacters;
		//building array of prices indexed by character
		for (int j = 0; j < paidcharacters; j++){
			cin >> letter >> price;
			letterPrices[letter] = price;
		}
		
		cin >> articleLines;
		cin.ignore(); //use this otherwise we lose a line
		//iterating over lines
		for (int j = 0; j < articleLines; j++) {
			getline(cin, line);
			//iterating over character per line
			for (int k = 0; k < line.length(); k++) {
				totalPrice += letterPrices[line[k]];
			}
		}
		
		//output formatted earlier with iomanip
		cout << totalPrice / 100 << "$\n";

		
		
	}
    
	return 0;
}