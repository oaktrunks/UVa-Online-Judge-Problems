//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Sudoku : 13115 : oaktrunks

//Data structure required : vector, bitset

//Tricks of the trade : using bitset for a quick array of bools
//						iterating over input and checking for duplicates
//						in the bitsets

/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, n, input; //number of test cases, width&height of sudoku, temp int for holding input
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> n;
		vector<vector<int> > sudoku(n);
		for (int x = 0; x < n; x++){ //reading in input square
			for (int y = 0; y < n; y++){
				cin >> input;
				sudoku[x].push_back(input);
			}
		}
		//validating
		int sqrtN = (int)sqrt(n); //sqrt(n) is always guaranteed to be an integer value
		bool correct = true;
		bitset<26> row;
		vector<bitset<26> > cols(n);
		vector<bitset<26> > squares(sqrtN);

		for (int x = 0; x < n && correct; x++){ //iterating over sudoku square
			row.reset(); //reset row bitset
			if (x % sqrtN == 0){
				for (int k = 0; k < sqrtN; k++){
					squares[k].reset(); //reset squares when you have checked first row of squares
				}
			}
			for (int y = 0; y < n && correct; y++){
				//checking row
				if (row[sudoku[x][y]])
					correct = false;
				else
					row[sudoku[x][y]] = 1;

				//checking column
				if (cols[y][sudoku[x][y]])
					correct = false;
				else
					cols[y][sudoku[x][y]] = 1;

				//checking square
				if (squares[y / sqrtN][sudoku[x][y]])
					correct = false;
				else
					squares[y / sqrtN][sudoku[x][y]] = 1;
			}
		}
		correct ? cout << "yes\n" : cout << "no\n";

	}

	return 0;
}