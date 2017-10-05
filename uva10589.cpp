//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Area : 10589 : oaktrunks

//Data structure required : 

//Tricks of the trade : Use the distance formula to tell if a point
//						is inside the striped area.
//						the point has to be less than 'a' away from
//						each corner.

/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N, a; //number of pairs and length of rectangle
	double x, y; //coordinates

	while (cin >> N >> a){
		if (N == 0 && a == 0){ //input terminated
			break;
		}
		int M = 0; //holds number of points inside striped area
		for (int i = 0; i < N; i++){
			cin >> x >> y;

			double xSq = x*x; //distance from left edge squared
			double ySq = y*y; //distance from bottom edge squared
			double aSq = a*a; //radius of circle squared
			double aySq = (a - y)*(a - y); //distance from top edge squared
			double axSq = (a - x)*(a - x); //distance from right edge squared
			
			if (xSq + ySq < aSq && xSq + aySq < aSq //bottom left & top left corner
				&& axSq + aySq < aSq && axSq + ySq < aSq) //top right & bottom right corner
				M++; //increment counter of points inside striped area

		}
		cout << fixed << setprecision(5) << double(M)*a*a / N << "\n";
	}

	return 0;
}
