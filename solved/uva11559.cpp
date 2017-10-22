#include <iostream>

using namespace std;

int main() {

	int N, B, H, W;// participants, budget, hotels, weeks
	int p, a;
	while (cin >> N >> B >> H >> W) {
		int min = B + 1;
		for (int i = 0; i < H; i++) {
			cin >> p;
			int impossibles = 0;
			for (int j = 0; j < W; j++) {
				cin >> a;
				if (a < N)
					impossibles++;
			}
			if (impossibles < W && p * N < min) {
				min = p * N;
			}
		}
		if (min < B + 1) {
			cout << min << endl;
		}
		else
			cout << "stay home\n";
	}



	return 0;
}