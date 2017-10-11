#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int a, b;

	cin >> a >> b;
	while (a != 0 || b != 0) {
		int count = 0;
		int current = 10;

		for (int i = 0; i < 9; i++) {
			if (a%current + b%current >= current)
				count++;
			current *= 10;
		}

		if (count > 1) cout << count << " carry operations.\n";
		else if (count == 1) cout << count << " carry operation.\n";
		else cout << "No carry operation.\n";
			

		cin >> a >> b;
	}

	return 0;
}