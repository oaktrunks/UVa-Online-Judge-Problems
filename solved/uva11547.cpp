#include <iostream>

using namespace std;

int main() {
	int cases, n;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> n;
		n = (n * 567 / 9 + 7492) * 235 / 47 - 498;
		if (n < 0)
			cout << n % 100 / 10 * -1 << '\n';
		else
			cout << n % 100 / 10 << '\n';
	}
	return 0;
}