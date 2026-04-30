// solved on thu april 16th 2026 at 13:27
#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef vector<vector<int>> adjacency_list;

int main() {
	speed

	int n; cin >> n;
	adjacency_list adj(n);

	while (true) {
		int a,b; cin >> a >> b;
		if (a == -1 && b == -1) break;
		if (a >= n || b >= n) continue;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int src,zombies,bunker; cin >> src >> zombies >> bunker;

	unordered_map<int,bool> visited;
	unordered_map<int,int> dist;
	visited[src] = true;
	dist[src] = 0;
	queue<int> q;
	q.push(src);
	
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (auto& neighbor : adj[cur]) {
			if (visited[neighbor] || neighbor == zombies) continue;
			
			visited[neighbor] = true;
			dist[neighbor] = dist[cur] + 1;
			q.push(neighbor);
		}
	}

	dist[bunker] == 0 ? cout << -1 : cout << dist[bunker];

	return 0;
}
