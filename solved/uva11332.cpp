#include <iostream>

using namespace std;

int f(int n) {
	if (n < 10) return n;
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	f(sum);
}

int main() {
	int input;
	while (cin >> input && input != 0) {
		cout << f(input) << endl;
	}

	return 0;
}