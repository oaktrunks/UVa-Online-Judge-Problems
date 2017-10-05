//////////////////////////////////////////////////////////////////////

//Daniel Tomei : CD : 11849 : oaktrunks

//Data structure required : set

//Tricks of the trade : set.insert(val) returns a pair where the second
//						element is set to false if is val already in the set
//						in the set, so everytime it returns false increment
//						a counter, output counter at end

//						doing it this way is faster than using
//						set_intersect from <algorithm>
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; //number of CDs owned by jack and jill
	int temp;

	cin >> N >> M;
	while (N > 0 && M > 0){
		set<int> CDs;
		int counter = 0;
		for (int i = 0; i < N; i++){ //jack input
			cin >> temp;
			CDs.insert(temp);
		}

		for (int i = 0; i < M; i++){ //jill input
			cin >> temp;
			if (!CDs.insert(temp).second){ //if already in set
				counter++;
			}
		}
		cout << counter << '\n';

		cin >> N >> M;
	}

	return 0;
}