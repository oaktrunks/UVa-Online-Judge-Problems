#include <iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long a, b;
	while (cin >> a >> b) {
		if (a > b) cout << a - b << endl;
		else cout << b - a << endl;
	}

	return 0;
}