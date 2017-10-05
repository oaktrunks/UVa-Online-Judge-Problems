//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Wetlands of Florida : 469 : oaktrunks

//Data structure required : vector, string, stringstream

//Tricks of the trade : using a vector of strings for the 2d matrix
//						then recursively count the number of W's connected
//						using string stream to easily get integers from
//						getline

/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//global 2D vector to store our input grid
vector<string> gridCopy;

//recursive function to return size of body of water
int waterSize(int x, int y){
	if (gridCopy[x][y] == 'L')
		return 0;
	else{
		gridCopy[x][y] = 'L';
		return 1 + waterSize(x - 1, y - 1) + waterSize(x - 1, y) + waterSize(x - 1, y+1)
				+ waterSize(x, y - 1) + waterSize(x, y) + waterSize(x, y + 1)
				+ waterSize(x + 1, y - 1) + waterSize(x + 1, y) + waterSize(x + 1, y + 1);
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int cases; //stores number of cases
	int x, y, padding; //coordinate x, coordinate y, width of matrix
	string line; //for reading in lines from input
	cin >> cases;
	cin.ignore(); //always when swapping between cin and getline
	cin.ignore(); //getting rid of blank line
	for (int i = 0; i < cases; i++){
		if (i > 0) cout << '\n'; //spacing between cases
		vector<string> originalGrid; //stores our input matrix
		getline(cin, line);
		padding = line.length() + 2;
		originalGrid.push_back(string(padding, 'L')); //creating first line of padding to avoid subscript errors
		originalGrid.push_back('L' + line + 'L');	 //Extra L concatenated at start and end for padding
		while (getline(cin, line) && line[0] > '9'){//keep reading in as long as we are still reading letters
			originalGrid.push_back('L' + line + 'L');
		}
		originalGrid.push_back(string(padding, 'L')); //pad bottom too


		//Processing
		gridCopy = originalGrid;
		stringstream stream(line);
		stream >> x >> y;
		cout << waterSize(x, y) << '\n';
		while (getline(cin, line) && line != ""){ //stop at empty line or EOF
			gridCopy = originalGrid;
			stringstream stream(line);
			stream >> x >> y;
			cout  << waterSize(x, y) << '\n';
		}

	}

	return 0;
}