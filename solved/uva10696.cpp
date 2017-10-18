#include <iostream>

using namespace std;

int f91(int N) {
	if (N <= 100) return f91(f91(N + 11));
	else return N - 10;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N;
	while (cin >> N && N != 0) {
		cout << "f91(" << N << ") = " << f91(N) << endl;
	}

	return 0;
}