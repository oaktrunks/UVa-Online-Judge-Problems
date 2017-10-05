//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Sin Cos Problem : 12575 : oaktrunks

//Data structure required : 

//Tricks of the trade : use derivative to find a critical point
//                      then use pi and 2*pi to manipulate this
//                      point and get the point we want.

/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; //number of test cases
	double A, B; //input ints
	double answerX, answerY; //x and y coords of maximum

	double pi = acos(-1);//defined in problem
	double twoPi = 2*pi;
	cin >> T;
	for (int i = 0; i < T; i++){
		cin >> A >> B;
		if (A == 0 && B == 0){ //inputs are both 0
			cout << "0.00 0.00\n";
			continue;
		}
		answerX = atan(A / B);
		answerY = A*sin(answerX) + B*cos(answerX);
		if (answerY < 0){ //make sure answer Y is positive
			answerX += pi;
			answerY *= -1;
		}
		while (answerX < 0){ //make sure answerX is positive
			answerX += twoPi;
		}
		while (answerX > twoPi){ //make sure answerX is smallest positive answer
			answerX -= twoPi;
		}

		cout << fixed << setprecision(2) << answerX << " " << answerY << '\n';
	}

	return 0;
}