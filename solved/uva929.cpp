// u10986.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int ShortestPath(vector<vector<ii> > adj, int first, int last) {
	//cout << "hi";
	vector<int> dist(adj.size(), INT_MAX); dist[first] = 0;
	priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, first));
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		for (int j = 0; j < (int)adj[u].size(); j++) {
			ii  v = adj[u][j];
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
	return dist[last];
}

int main()
{
	int N, numRows, numCols, weight;
	//int server1, server2, weight;
	int shortest_path;

	cin >> N; //num cases
	for (int i = 0; i < N; i++) {
		cin >> numRows >> numCols;
		vector<vector<ii> > adj(numRows*numCols);
		vector<int> weights(numRows*numCols);
		for (int j = 0; j < numRows; j++) {
			for (int c = 0; c < numCols; c++) {
				/*cin >> server1 >> server2 >> w;
				adj[server1].push_back(ii(server2, w));
				adj[server2].push_back(ii(server1, w));*/
				cin >> weight;

				int currentIndex = c + numCols* j;
				weights[currentIndex] = weight;
			}
			//
		}

		//int numV = numRows*numCols;
		for (int j = 0; j < numRows; j++) {
			for (int c = 0; c < numCols; c++) {
			//	//cin >> server1 >> server2 >> w;
			//	/*adj[j].push_back(ii(server2, w));
			//	adj[server2].push_back(ii(server1, w));*/
				int currentIndex = c + numCols* j;
				//if (currentIndex >= numRows*numCols) break;
				if(c > 0) // check if not on first column adding left
					adj[currentIndex].push_back(ii(currentIndex - 1, weights[currentIndex - 1]));
				if(c < numCols - 1) // check if not on last column adding right
					adj[currentIndex].push_back(ii(currentIndex + 1, weights[currentIndex + 1]));
				if(j > 0) // check if not on first row adding above
					adj[currentIndex].push_back(ii(currentIndex - numCols, weights[currentIndex - numCols]));
				if (j < numRows - 1) // check if not on last row adding below
					adj[currentIndex].push_back(ii(currentIndex + numCols, weights[currentIndex + numCols]));
				//3 + 4 + 5*3 = 
			}
			//
		}
		//cout << "hi";
		shortest_path = ShortestPath(adj, 0, numCols*numRows - 1) + weights[0];
		cout << shortest_path << endl;
		//if (shortest_path == INT_MAX) cout << "Case #" << i + 1 << ": unreachable\n";
		//else cout << "Case #" << i + 1 << ": " << shortest_path << endl;
	}

	return 0;
}