// solved on thu april 16th 2026 at 13:16
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

	int src; cin >> src;

	unordered_map<int,bool> visited;
	vector<int> distances(n,-1);
	distances[src] = 0;
	visited[src] = true;
	queue<int> q;
	q.push(src);
	while (!q.empty()) {
		int top = q.front(); q.pop();
		for (auto& neighbor : adj[top]) {
			if (visited[neighbor]) continue;
			visited[neighbor] = true;
			distances[neighbor] = distances[top] + 1;
			q.push(neighbor);
		}
	}

	for (int i = 0; i < distances.size(); ++i)
		cout << i << ':' << distances[i] << endl;

	return 0;
}
