//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Big Mod : 374 : oaktrunks

//Data structure required : 

//Tricks of the trade : modified fastExp function from
//                       pg 365 of Competitive Programming 3
//						 to work with modulus

//////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

//Modified fastExp from pg 365 of Competitive Programming 3
//calculates remainder of big number division in the form 
// of base ^ p % m
int modPow(long long base, long long p, long long m){
	if (p == 0) return 1 %m;
	else if (p == 1) return base%m;
	else{
		int res = modPow(base, p / 2, m); 
		res = res * res % m;
		if (p % 2 == 1) res = res * base % m;
		return res;
	}
}

int main(){
	long long B, P, M; //base, exponent, mod
	while (cin >> B >> P >> M){
		cout << modPow(B, P, M) << '\n';
	}

	return 0;
}