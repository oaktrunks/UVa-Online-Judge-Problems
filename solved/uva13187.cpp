#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	long t, s; //number of test cases, sum
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> s;
		cout << s*s + (s<<1) << "\n";

		//solution below works too, above one is 0.010 faster
		/*s++;
		cout << s*s - 1 << "\n";*/
	}
}