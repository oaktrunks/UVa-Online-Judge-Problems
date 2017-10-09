#include <iostream>

using namespace std;

int main() {
	int T; //number of test cases
	int worker1, worker2, worker3;

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> worker1 >> worker2 >> worker3;
		cout << "Case " << i << ": ";
		if (worker1 < worker2) {
			if (worker3 > worker2)
				cout << worker2 << endl;
			else if (worker3 > worker1)
				cout << worker3 << endl;
			else
				cout << worker1 << endl;
		}
		else{ //worker1 > worker2
			if (worker3 > worker1)
				cout << worker1 << endl;
			else if (worker3 > worker2)
				cout << worker3 << endl;
			else
				cout << worker2 << endl;
		}
	}
}