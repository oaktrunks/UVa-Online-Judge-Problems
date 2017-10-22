#include <iostream>

using namespace std;
int main() {

	int H, U, D, F; //height of well, distance up, distance down, fatigue percent

	while (cin >> H >> U >> D >> F && H != 0) {
		/*double fatigue = double(F) / 100.0 * double(U);
		double currentHeight = 0.0;*/
		int currentHeight = 0;
		H *= 100; U *= 100; D *= 100; //Moving scale up so we don't have to deal with doubles
		int fatigue = F * U / 100;
		bool floored = false;
		bool out = false;
		int days = 0;
		while (/*currentHeight < double(H) &&*/!floored && !out) {
			//Climb up
			if (U > 0)
				currentHeight += U;

			//Check if out
			if (currentHeight > double(H))
				out = true;

			//Sleep and slide down
			currentHeight -= double(D);

			//Check if on floor
			if (currentHeight < double(0)) {
				floored = true;
			}

			U -= fatigue;
			days++;
		}
		if (out) {
			cout << "success on day " << days << endl;
		}
		else{
			cout << "failure on day " << days << endl;
		}
	}

	return 0;
}