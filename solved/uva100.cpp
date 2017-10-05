#include <iostream>

using namespace std;

int cycle(int n, int counter) {
	counter++;
	if (n == 1) return counter;
	if (n % 2 == 1) cycle(3 * n + 1, counter);
	else cycle(n / 2, counter);
}

int main() {
	int a, b, max, temp, low, high;
	while (cin >> a) {
		cin >> b;
		if (a < b) {
			low = a;
			high = b;
		}
		else {
			high = a; low = b;
		}
		max = 0;
		for (int n = low; n <= high; n++) {
			temp = cycle(n, 0);
			if (temp > max) {
				max = temp;
			}
		}
		cout << a << " " << b << " " << max << endl;
	}
}