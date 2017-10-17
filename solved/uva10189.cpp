#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, m;
	string temp;
	string pad = "";
	vector<string> grid;
	int iteration = 0;
	while (cin >> n >> m && (n != 0 || m != 0)) {
		grid.clear();
		cin.ignore();
		iteration++;
		////Pad input grid so we don't go out of bounds
		//for (int i = 0; i < n; i++) {
		//	pad += '0';
		//}
		//grid.push_back('0' + pad + '0');
		//Get input grid
		for (int i = 0; i < n; i++) {
			getline(cin, temp);
			//temp = '0' + temp + '0';
			grid.push_back(temp);
		}
		//grid.push_back('0' + pad + '0');
		//Iterate over grid
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '.') {
					grid[i][j] = '0';
				}

				else if (grid[i][j] == '*') {
					//Iterate over adjacent squares, increment or set to 1
					for (int k = -1; k < 2; k++) {
						for (int l = -1; l < 2; l++) {
							if (i - k < 0 || j - l < 0 || i - k >= n || j - l >= m || grid[i - k][j - l] == grid[i][j]) {}
							else {
								if (grid[i - k][j - l] == '.')
									grid[i - k][j - l] = '1';
								else if (grid[i - k][j - l] != '*') grid[i - k][j - l] = char(int(grid[i - k][j - l]) + 1);
							}
						}
					}
				}
			}
		}

		//Output grid
		if (iteration > 1) cout << endl;
		cout << "Field #" << iteration << ":\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << grid[i][j];
			}
			cout << endl;
		}
	}
}