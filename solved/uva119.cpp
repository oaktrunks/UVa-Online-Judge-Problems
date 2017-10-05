#include <vector>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main() {
	int n, cash, presents, leftover, temp;
	int iteration = 0;
	string name , name2;
	while (cin >> n) {
		if(iteration > 0)
			cout << endl;
		iteration++;
		//cout << "looping";
		vector<pair<string, int>> names_money;
		//getting names into vector
		for (int i = 0; i < n; i++) {
			//cout << "looping1";
			cin >> name2;
			names_money.push_back(pair<string, int>(name2,0));
		}

		//getting money spent
		for (int i = 0; i < n; i++) {
			//cout << "looping2";
			cin >> name >> cash;
			for (int j = 0; j < n; j++) {
				if (name == names_money[j].first) {
					names_money[j].second -= cash;
				}
			}

			cin >> presents;
			if (presents) {
				temp = cash;
				cash = cash / presents;
				leftover = temp - cash*presents;
				//adding left-over
				for (int j = 0; j < n; j++) {
					if (name == names_money[j].first) {
						names_money[j].second += leftover;
					}
				}

				for (int j = 0; j < presents; j++) {
					//cout << "looping3";
					cin >> name2;
					for (int g = 0; g < n; g++) {
						//cout << "looping4";
						if (name2 == names_money[g].first) {
							names_money[g].second += cash;
						}
					}
				}
			}
			else {
				leftover = cash;
				//adding left-over
				for (int j = 0; j < n; j++) {
					if (name == names_money[j].first) {
						names_money[j].second += leftover;
					}
				}
			}

		}
		for(int h = 0; h < n; h++) {
			//cout << "looping5";
			cout << names_money[h].first;
			cout << " " << names_money[h].second << endl;
		}
	}



	return 0;
}