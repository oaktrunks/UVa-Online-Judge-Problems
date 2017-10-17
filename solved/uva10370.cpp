#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
int main() {
	int C, N, temp;
	vector<int> finals;

	cin >> C;
	for (int i = 0; i < C; i++) {
		finals.clear();
		int sum = 0;
		int count = 0;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> temp;
			sum += temp;
			finals.push_back(temp);
		}
		double avg = double(sum) / N;
		for (int j = 0; j < N; j++) {
			if (double(finals[j]) > avg) {
				//cout << "incrementing count" << endl;
				count++;
			}
		}
		//cout << count << "/" << N << " * 100 = " << count / N * 100 << endl;
		cout << fixed << setprecision(3) << double(count) / N * 100 << "%" << endl;
	}
	return 0;
}