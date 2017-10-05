//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Ferry Loading III : 10901 : oaktrunks

//Data structure required : queues

//Tricks of the trade : using pairs of ints to index arrival time and arrival order
//						two queues, one for each bank
//						vector for outputting in the correct order
//						and a bunch of if statements to fill vector
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int timeToCross, cases, maxCarLoad, cars, currentTime, temp;
	bool ferryIsRight;
	string side;
	cin >> cases;
	for (int i = 0; i < cases; i++){
		cin >> maxCarLoad >> timeToCross >> cars;
		queue<pair<int, int> > leftBank, rightBank; //these hold the time each car arrived 
												//and which order they were received in input
		vector<int> carTimes(cars); //holds cars dropped off in input order for each case
		for (int j = 0; j < cars; j++){
			cin >> temp >> side;
			if (side == "left")
				leftBank.push(pair<int,int>(temp, j));
			else
				rightBank.push(pair<int, int>(temp, j));
		}

		currentTime = 0; ferryIsRight = false;

		while (!leftBank.empty() || !rightBank.empty()){ //there are still cars to be picked up
			int carsPickedUp = 0;

			if (!ferryIsRight){ //ferry is at left bank
				//loop through bank and pickup all possible cars
				while (!leftBank.empty() && leftBank.front().first <= currentTime && carsPickedUp < maxCarLoad){
					carsPickedUp++;
					carTimes[leftBank.front().second] = currentTime + timeToCross;
					leftBank.pop();
				}
			}

			else{ //ferry is at right bank
				while (!rightBank.empty() && rightBank.front().first <= currentTime && carsPickedUp < maxCarLoad){
					carsPickedUp++;
					carTimes[rightBank.front().second] = currentTime + timeToCross;
					rightBank.pop();
				}
			}

			//check for case where no cars to pick up
			if (!carsPickedUp){
				//check which bank has first arrival
				if (!leftBank.empty() && !rightBank.empty()){
					if (leftBank.front() < rightBank.front()){// first arrival is left
						if (!ferryIsRight) //just move time up to left arrival
							currentTime = leftBank.front().first;
						else{ //move to left bank
							ferryIsRight = false;
							if (leftBank.front().first < currentTime)
								currentTime += timeToCross;
							else
								currentTime = leftBank.front().first + timeToCross;
						}
					}
					else{//first arrival is right
						if (ferryIsRight) //just move time up to right arrival
							currentTime = rightBank.front().first;
						else{ //move to right bank
							ferryIsRight = true;
							if (rightBank.front().first < currentTime)
								currentTime += timeToCross;
							else
								currentTime = rightBank.front().first + timeToCross;
						}
					}
				}
				else if (leftBank.empty()){
					if (ferryIsRight) //just move time up to right arrival
						currentTime = rightBank.front().first;
					else{ //move to right bank
						ferryIsRight = true;
						if (rightBank.front().first < currentTime)
							currentTime += timeToCross;
						else
							currentTime = rightBank.front().first + timeToCross;
					}
				}
				else{//right bank is empty
					if (!ferryIsRight) //just move time up to left arrival
						currentTime = leftBank.front().first;
					else{//move to left bank
						ferryIsRight = false;
						if (leftBank.front().first < currentTime)
							currentTime += timeToCross;
						else
							currentTime = leftBank.front().first + timeToCross;
					}
				}
			}
			else{ //cars have been picked up
				ferryIsRight = !ferryIsRight;
				currentTime += timeToCross;
			}

		}
		if (i) cout << '\n'; //newline before each new case
		for (int j = 0; j < cars; j++){
			cout << carTimes[j] << "\n";
		}
	}

	return 0;
}