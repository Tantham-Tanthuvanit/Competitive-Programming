#include <bits/stdc++.h>
#include <queue>
using namespace std;

void bfs(int node, vector<vector<int>>& adj, vector<int>& dist, vector<bool>& visited) {
	dist[node] = 0;
	visited[node] = true;

	queue<int> q;
	q.push(node);

	while (!q.empty()) {
		int nd = q.front();q.pop();

		for (int neigh : adj[nd]) {
			if (visited[neigh]) continue;
			visited[neigh] = true;
			dist[neigh] = dist[nd] + 1;
			q.push(neigh);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> adj(n);

	return 0;
}
