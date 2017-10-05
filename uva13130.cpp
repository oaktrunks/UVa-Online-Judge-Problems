//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Cacho : 13130 : oaktrunks

//Data structure required : vector

//Tricks of the trade : In class solutions.
//						One uses only cin, other only getline

/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

bool isValid(vector<int> dice){ //Takes in a vector
	for (int i = 1; i < dice.size(); i++){
		if (dice[i] != dice[i - 1] + 1) return false;
	}
	return true;
}

/*
	CIN METHOD
*/
//int main(){
//	ios_base::sync_with_stdio(false); cin.tie(0);
//	int T; //number of test cases
//	int input;
//	cin >> T;
//	for (int i = 0; i < T; i++){
//		vector<int> dice;
//		for (int j = 0; j < 5; j++){
//			cin >> input;
//			dice.push_back(input);
//		}
//		if (isValid(dice)) cout << "Y\n"; else cout << "N\n";
//	}
//
//	return 0;
//}

/*
	GETLINE METHOD
*/
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; //number of test cases
	int input;
	string line; 
	getline(cin, line);
	T = stoi(line); //converting string to int
	for (int i = 0; i < T; i++){
		vector<int> dice;
		getline(cin, line);
		stringstream stream(line);
		for (int j = 0; j < 5; j++){
			stream >> input;
			dice.push_back(input);
		}
		if (isValid(dice)) cout << "Y\n"; else cout << "N\n";
	}

	return 0;
}