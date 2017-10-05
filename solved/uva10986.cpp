//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Sending Email : 10986 : oaktrunks

//Data structure required : vector, queue

//Tricks of the trade : Using Dijkstra's from the green book

/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> ii;

int ShortestPath(vector<vector<ii> > adj, int first, int last) {
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
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N, n, m, S, T;
	int server1, server2, w;
	int shortest_path;

	cin >> N; //num cases
	for (int i = 0; i < N; i++) {
		cin >> n >> m >> S >> T; // m = edges
		vector<vector<ii> > adj(n);
		for (int j = 0; j < m; j++) {
			cin >> server1 >> server2 >> w;
			adj[server1].push_back(ii(server2, w));
			adj[server2].push_back(ii(server1, w));
		}
		shortest_path = ShortestPath(adj, S, T);
		if (shortest_path == INT_MAX) cout << "Case #" << i+1 << ": unreachable\n";
		else cout << "Case #" << i+1 << ": " << shortest_path << endl;
	}

	return 0;
}