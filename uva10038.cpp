//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Jolly Jumpers : 10038 : OakTrunks

//Data structure required : Vectors

//Tricks of the trade : math.h for abs()

/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	int n;
	int num, diff;
	bool isJolly; //decides if sequence is jolly

	while (cin >> n){
		vector<bool> jolly(n, false); //holds true or false for values depending if they got hit
		vector<int> nums;	//holds input number sequence
		isJolly = true;

		//read in all numbers in case
		for (int i = 0; i < n; i++){
			cin >> num;
			nums.push_back(num);
		}

		for (int i = 1; i < n; i++){
			diff = abs(nums[i-1] - nums[i]);

			//check if difference out of range 1 to n-1 -> not jolly
			if (diff >= n || diff == 0){
				isJolly = false;
				break;
			}

			//check if duplicate difference -> not jolly
			else if (jolly[diff] == true){
				isJolly = false;
				break;
			}

			else
				jolly[diff] = true;

		}
		
		//output final decision
		if (isJolly)
			cout << "Jolly\n";
		else
			cout << "Not jolly\n";
	}

	return 0;
}