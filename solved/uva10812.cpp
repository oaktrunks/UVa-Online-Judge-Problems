#include <iostream>

using namespace std;
int main() {
	int cases;
	int a, b;
	int c, d;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> a >> b;
		bool found = false;
		if (a < b || a + b % 2 == 1) {
			cout << "impossible\n";
			continue;
		}
		if (a == b) {
			cout << a << " 0\n";
			continue;
		}
		if (b == 0) {
			cout << (a >> 1) << " " << (a >> 1) << endl;
			continue;
		}
		else {
			c = a + 1; d = a - b + 1; //sum , sum - difference
			for (int i = 0; !found && i < a ; i++) {
				c--; d--;
				if (c + d == a)
					found = true;
			}
		}
		if (found) cout << c << " " << d << endl;
		else cout << "impossible" << endl;
	}

	return 0;
}