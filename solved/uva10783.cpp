#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int cases;
	int a, b;

	cin >> cases;
	for (int c = 1; c <= cases; c++) {
		cin >> a >> b;
		int sum = 0;
		for (int i = a; i <= b; i++) {
			if (i % 2) sum += i;
		}
		cout << "Case " << c << ": " << sum << endl;
	}

	return 0;
}