#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string input;
	bool start = true;
	while (getline(cin, input)) {
		//cout << input;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '"') {
				start ? cout << "``" : cout << "''";
				start = !start;
			}
			else {
				cout << input[i];
			}
			if (i == input.length() - 1)
				cout << "\n";

		}
	}
	return 0;
}