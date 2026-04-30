// solved on wed april 15th 2026 at 16:41
#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);

void dfs(int src, unordered_map<int,bool>& visited, vector<vector<int>>& adj) {
	if (visited[src]) return;
	visited[src] = true;
	cout << src << ' ';
	for (auto neighbor : adj[src]) {
		dfs(neighbor,visited,adj);
	}
}

void bfs(int src, vector<vector<int>> adj) {
	queue<int> q;
	unordered_map<int,bool> visited;
	q.push(src);
	visited[src] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << ' ';

		for (int neighbor : adj[cur]) {
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
	}
}

int main() {
	int n; cin >> n;
	vector<vector<int>> adj(n);

	while (true) {
		char cmd; cin >> cmd;
		if (cmd == 's') break;
		int a,b,w; cin >> a >> b >> w;
		adj[a].push_back(b);
	}

	// sort adjacency list
	for (int i = 0; i < n; ++i)
		sort(adj[i].begin(),adj[i].end());

	while (true) {
		char cmd; cin >> cmd;
		if (cmd == 'q') break;
		int src; cin >> src;
		unordered_map<int,bool> visited;
		if (cmd == 'd') dfs(src,visited,adj);
		if (cmd == 'b') bfs(src,adj);

		cout << endl;
	}

	return 0;
}
