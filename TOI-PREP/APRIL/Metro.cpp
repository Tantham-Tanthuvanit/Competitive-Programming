// solved on thu april 16th 2026 at 12:57
#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef vector<vector<int>> adjacency_list;

int normal(int src, int dest, vector<vector<int>>& adj, vector<int>& zones) {
	unordered_map<int,bool> visited;
	unordered_map<int,int> distances;

	queue<int> q;
	visited[src] = true;
	distances[src] = 0;
	q.push(src);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (auto neighbor : adj[cur]) {
			if (visited[neighbor] || zones[neighbor] > 2) continue;
			visited[neighbor] = true;
			distances[neighbor] = distances[cur]+1;
			q.push(neighbor);
		}
	}

	return distances[dest] == 0 ? -1 : distances[dest];
}

int bfs(int src, int dest, vector<vector<int>>& adj) {
	unordered_map<int,bool> visited;
	unordered_map<int,int> distances;

	queue<int> q;
	visited[src] = true;
	distances[src] = 0;
	q.push(src);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (auto& neighbor : adj[cur]) {
			if (visited[neighbor]) continue;
			visited[neighbor] = true;
			distances[neighbor] = distances[cur]+1;
			q.push(neighbor);
		}
	}

	return distances[dest];
}

int main() {
	speed;
	int n; cin >> n;
	vector<int> zones(n);

	adjacency_list adj(n);

	// input zones
	for (int i = 0; i < n; ++i)
		cin >> zones[i];

	// input code
	while (true) {
		char cmd; cin >> cmd;
		if (cmd == 's') break;
		// input src to destination
		int a,b; cin >> a >> b;
		// undirected graph
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	while (true) {
		char cmd; cin >> cmd;
		if (cmd == 'q') break;
		int a,b; cin >> a >> b;
		// normal ticket [ zones 1 and 2 ]
		if (cmd == 'b') {
			cout << bfs(a, b, adj) << ' ';
			normal(a, b, adj, zones) < 0 ? cout << 'N' : cout << 'Y';
			cout << endl;
		} // special ticket [ all zones ]
		else if (cmd == 'd') {
			cout << bfs(a,b,adj) << " Y" << endl;
		}
	}

	return 0;
}
