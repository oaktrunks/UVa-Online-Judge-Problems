#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, f;
	unsigned long long a, b, c;

	cin >> n; //test cases
	for (int i = 0; i < n; i++) {
		cin >> f;
		unsigned long long sum = 0;
		for (int j = 0; j < f; j++) {
			cin >> a >> b >> c;
			sum += a*c;
		}
		cout << sum << endl;
	}

	return 0;
}