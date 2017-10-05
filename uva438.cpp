//////////////////////////////////////////////////////////////////////

//Daniel Tomei : The Circumference of the Circle : 438 : oaktrunks

//Data structure required : 

//Tricks of the trade : page 279 + 280 of Competiive Programming 3
//						using Heron's formula and finding a circumscribed
//						circle

/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	long double pi = 3.141592653589793;

	long double x1, x2, x3, y1, y2, y3; //holds coords of input points
	long double dist12, dist23, dist13, semiperim, area, radius;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
		
		//calculating lengths of side of triangle
		dist12 = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
		dist23 = sqrt(pow((x3 - x2),2) + pow((y3 - y2) ,2));
		dist13 = sqrt(pow((x3 - x1),2) + pow((y3 - y1),2));

		//calculating semi-perimeter and area of triangle (Heron's Formula)
		semiperim = (dist12 + dist23 + dist13) * 0.5;
		area = (4.0 * sqrt(semiperim * (semiperim - dist12) * (semiperim - dist23)*(semiperim - dist13)));

		radius = dist12 * dist23 * dist13 / area;

		cout << fixed << showpoint << setprecision(2)
			<< 2.0 * pi*radius
			<< "\n";
	}

	return 0;
}