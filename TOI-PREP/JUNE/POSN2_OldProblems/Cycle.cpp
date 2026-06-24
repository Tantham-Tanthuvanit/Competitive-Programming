#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int parent) {
	visited[node] = true;	

	for (int i : adj[node]) {
		if (!visited[i]) {
			if (dfs(i,adj,visited,node)) return true;
		}
		else if (i != parent)return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> adj(n);

	char c;
	while (true) {
		cin >> c;
		if (c == 's') break;

		int a,b,c; cin >> a >> b >> c;
		adj[a].push_back(b);
	}

	vector<bool> visited(n,false);
	if (dfs(0,adj,visited,-1)) cout << "Cycle";
	else cout << "No Cycle";

	return 0;
}
