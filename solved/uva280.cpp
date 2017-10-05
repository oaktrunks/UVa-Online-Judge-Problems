//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Rotations : 13193 : oaktrunks

//Data structure required : vector, queue

//Tricks of the trade : Using BFS to determine which vertices are
//						unreachable. 

/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, edge; //n = number of vertices in graph, edge = end node for input
	int cases, start; //cases = number of test cases per graph, start= start node
	while (cin >> n && n){
		vector<vector<int> > graph(n+1);

        //reading in data
		while(cin >> start && start){
			while (cin >> edge && edge){
				graph[start].push_back(edge);
			}
		}

        //test cases
		cin >> cases;
		for (int i = 0; i < cases; i++){
			cin >> start;

            //do BFS, pg 124 competitive programming slightly modified
			// to check for cycle back to starting vertex
			vector<int> d(n+1, -1);
			queue<int> q; q.push(start);
			while (!q.empty()){
				int u = q.front(); q.pop();
				for (int j = 0; j < (int)graph[u].size(); j++){
					int v = graph[u][j];
					if (d[v] == -1){
						d[v]++;
						q.push(v);
					}
				}
			}

			//checking which vertices are marked unreachable
			vector<int> inaccessible;
			for (int j = 1; j < (int)d.size(); j++){
				if (d[j] == -1){
					inaccessible.push_back(j);
				}
			}

			//outputting inaccessible vertices
			cout << inaccessible.size();
			for (int j = 0; j < (int)inaccessible.size(); j++){
				cout << " " << inaccessible[j];
			}
			cout << "\n";
		}
	}

	return 0;
}