// solved on wed april 15th 2026 at 17:10
#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef vector<vector<int>> adjacency_list;

void dfs(unordered_map<int,bool>& visited, int src, adjacency_list adj) {
	if (visited[src]) return;
	visited[src] = true;
	cout << src << ' ';
	for (int neighbor : adj[src])
		dfs(visited, neighbor, adj);
}

int main() {
	speed

	int n; cin >> n;
	adjacency_list adj(n);
	unordered_map<int,bool> visited;

	while (true) {
		char cmd; cin >> cmd;
		if (cmd == 's') break;
		int a,b,w; cin >> a >> b >> w;
		adj[a].push_back(b);
	}

	// ALWAYS SORT ADJACENCY LIST
	// WHEN SORTING NEVER FORGOT TO ADD THE & OR ELSE IT WILL NOT SORT
	for (auto& x : adj)
		sort(x.begin(), x.end());

	for (int i = 0; i < adj.size(); ++i) {
		if (!visited[i]) {
			dfs(visited, i, adj);
			cout << endl;
		}
	}

	return 0;
}
