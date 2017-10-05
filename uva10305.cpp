//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Ordering Tasks : 10305 : oaktrunks

//Data structure required : vector

//Tricks of the trade : using DFS, print out the nodes as they finish
//                      DFS is modified code from pg 126 of green book

/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

//global vectors
vector<int> dfs_num;
vector<vector<int> > AdjList;
vector<int> top; //output array for reverse order

void dfs2(int u){
	dfs_num[u] = 1; //1 for visited
	for (int j = 0; j < (int)AdjList[u].size(); j++){
		if (dfs_num[AdjList[u][j]] == -1)
			dfs2(AdjList[u][j]);
	}
	top.push_back(u);
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; //input: number of tasks, number of relations
	int i, j; //input: task i executed before task j

	while (cin >> n >> m && n != 0){
		top.clear();
		AdjList.clear();
		AdjList.resize(n + 1);
		for (int k = 0; k < m; k++){
			cin >> i >> j;
			AdjList[i].push_back(j);
		}
		//do DFS
		dfs_num.clear();
		dfs_num.resize(n + 1, -1); //-1 for unvisited
		for (int g = 1; g <= n; g++){
			if (dfs_num[g] == -1)
				dfs2(g);
		}

        //outputting top vector backwards
		cout << top[(int)top.size() - 1];
		for (int g = (int)top.size() - 2; g >= 0; g--){
			cout << " " << top[g];
		}
		cout << endl;
	}
    

	return 0;
}