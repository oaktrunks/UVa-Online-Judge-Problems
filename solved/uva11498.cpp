#include <iostream>

using namespace std;
int main() {

	int  K, N, M, X, Y;
	ios_base::sync_with_stdio(false); cin.tie(0);

	while (cin >> K) {
		//cout << "in main while loop with K = " << K << endl;
		if (K == 0) break;
		cin >> N >> M; //Coordinates of divisor
		//cout << "N = " << N << "  M = " << M << endl;
		for (int i = 0; i < K; i++) {
			//cout << "in test cases with K = " << K << endl;
			cin >> X >> Y;
			//cout << "X = " << X << "  Y = " << Y << endl;
			if (X ==  N || Y == M) {
				cout << "divisa\n";
			}
			else {
				if (Y > M) {
					cout << 'N';
				}
				else {
					cout << 'S';
				}

				if (X > N) {
					cout << "E\n";
				}
				else {
					cout << "O\n";
				}
			}
		}
	}

	return 0;
}