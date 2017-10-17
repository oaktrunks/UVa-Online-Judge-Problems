#include <iostream>

using namespace std;

int main() {

	long long N, P;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P;
		bool isPalindrome = false;
		long long iterations = 0;
		while (!isPalindrome) {
			//check if palindrome
			long long reverse = 0;
			long long digit;
			long long temp = P;
			do
			{
				digit = temp % 10;
				reverse = (reverse * 10) + digit;
				temp = temp / 10;
			} while (temp != 0);
			P += reverse;
			iterations++;
			reverse = 0;
			temp = P;
			do
			{
				digit = temp % 10;
				reverse = (reverse * 10) + digit;
				temp = temp / 10;
			} while (temp != 0);
			//cout << "reverse =" << reverse << ", P = " << P << endl;
			if (P == reverse) isPalindrome = true;

		}
		cout << iterations << " " << P << endl;
	}

	return 0;
}