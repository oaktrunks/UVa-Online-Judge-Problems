#include <iostream>

using namespace std;
int main() {
	
	int T, N, temp;

	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >> N;
		int max = 0;
		for (int j = 0; j < N; j++) {
			cin >> temp;
			if (temp > max)
				max = temp;
			
		}
		cout << "Case " << i << ": " << max << endl;
	}

	return 0;
}