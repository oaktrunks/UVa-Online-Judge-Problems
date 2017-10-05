//////////////////////////////////////////////////////////////////////

//Daniel Tomei : GCD LCM : 11388 : oaktrunks

//Data structure required : 

//Tricks of the trade : no math required

/////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int cases, G, L; //input variables
	cin >> cases;
	for (int i = 0; i < cases; i++){
		cin >> G >> L;
        //G has to be smaller than L. and L has to be divisible by G
        // then just output G << L otherwise output -1
		L >= G && L % G == 0 ? cout << G << " " << L << '\n': cout << "-1\n";
	}

	return 0;
}