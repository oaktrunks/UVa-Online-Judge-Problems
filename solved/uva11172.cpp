/////////////////////////////////////////////////////////////////////
//
//Daniel Tomei : Relational Operator : 11172 : OakTrunks
//
//Data structure required : 
//
//Tricks of the trade :
//
/////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
	int t, a, b; 

	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> a >> b;
		if (a < b)
			cout << "<\n";
		else if (a > b)
			cout << ">\n";
		else
			cout << "=\n";
	}

	return 0;
}