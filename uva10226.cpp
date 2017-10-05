//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Hardwood Species : 10226 : oaktrunks

//Data structure required : unordered_map, vector, string

//Tricks of the trade : unordered_map with a sorted vector is faster
//						than using map

/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int cases;
	string tree;
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> cases; cin.ignore();
	getline(cin, tree); //getting rid of blank line
	for (int i = 0; i < cases; i++){
		vector<string> treeNames;
		unordered_map<string, int> treeAmount;
		int totalTrees = 0;
		while (getline(cin, tree)){
			if (tree.empty())
				break;
			if (!treeAmount[tree]) //checking if already in vector
				treeNames.push_back(tree);

			treeAmount[tree]++;
			totalTrees++;
		}
		if (i > 0)
			cout << '\n';

        //sorting vector to be alphabetical
		sort(treeNames.begin(), treeNames.end());

		cout << fixed << setprecision(4);
		for (int j = 0; j < treeNames.size(); j++){
			cout << treeNames[j] << " " << double(treeAmount[treeNames[j]]) / totalTrees * 100 << '\n';
		}
	}

	return 0;
}
