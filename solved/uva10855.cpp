//////////////////////////////////////////////////////////////////////
/*
Daniel Tomei : Rotated Square : 10855 : oaktrunks

Data structure required : vectors

Tricks of the trade : 
*/
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

using namespace std;

//prototypes
void rotateRight(vector<vector<char> > &square);

int main(){

	int big, small;
	char letter;
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> big >> small;
	while (big > 0 || small > 0) {
		vector<vector<char> > bigSquare(big);
		vector<vector<char> > smallSquare(small);
		vector<int> rotationHit(4);

		//reading in bigSquare
		for (int i = 0; i < big; i++) {
			for (int j = 0; j < big; j++) {
				cin >> letter;
				bigSquare[i].push_back(letter);
			}
		}

		//reading in smallSquare
		for (int i = 0; i < small; i++) {
			for (int j = 0; j < small; j++) {
				cin >> letter;
				smallSquare[i].push_back(letter);
			}
		}

		//check four rotations
		for (int rotation = 0; rotation < 4; rotation++) {
			//iterating rows
			for (int y = 0; y <= (big - small); y++) {
				//iterating columns
				for (int x = 0; x <= (big - small); x++) {
					//[y][x] is top left corner of our current test case
					// checking if that left corner == top left corner of smallSquare
					bool inside = true;
					if (bigSquare[y][x] == smallSquare[0][0]) {
						//start testing rest of square
						for (int smallY = 0; smallY < small; smallY++) {
							for (int smallX = 0; smallX < small; smallX++) {
								if (bigSquare[y + smallY][x + smallX] != smallSquare[smallY][smallX]) {
									inside = false;
									break;
								}
							}
							if (!inside) {
								break;
							}
						}
					}
					else {
						inside = false;
					}

					if (inside) {
						rotationHit[rotation]++;
					}
				}
			}

			rotateRight(smallSquare);
		}
		cout << rotationHit[0] << " " << rotationHit[1] << " " << rotationHit[2] << " " << rotationHit[3] << "\n";
		cin >> big >> small;
	}

	return 0;
}

void rotateRight(vector<vector<char> > &square){
	int width = square.size();

	vector<vector<char> > tempSquare(width);
	tempSquare = square;
	for (int i = 0; i < width; i++){
		for (int j = width - 1; j >= 0; j--){
			square[i][(width-1) - j] = tempSquare[j][i];
		}
	}
}