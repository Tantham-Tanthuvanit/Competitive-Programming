#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
	cout << node << ' ';
	visited[node] = true;

	for (int neigh : adj[node]) {
		if (visited[neigh]) continue;
		dfs(neigh,adj,visited);
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> adj(n);

	char cmd = 'x';
	while (true) {
		cin >> cmd;
		if (cmd == 's') break;
		int a,b,w; cin >> a >> b >> w;
		adj[a].push_back(b);
	}

	vector<bool> visited(n,false);
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) dfs(i,adj,visited);
		cout << endl;
	}

	return 0;
}
