#include <bits/stdc++.h>
using namespace std;

void normal(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& zones, vector<int>& dist) {
	queue<int> q;
	dist[node] = 0;
	visited[node] = true;
	q.push(node);

	while (!q.empty()) {
		int node = q.front(); q.pop();
		
		for (int neighbor : adj[node]) {
			if (zones[neighbor] >= 3) continue;
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				dist[neighbor] = dist[node] + 1;
				q.push(neighbor);
			}
		}
	}
}

void special(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& zones, vector<int>& dist) {
	queue<int> q;
	dist[node] = 0;
	visited[node] = true;
	q.push(node);

	while (!q.empty()) {
		int node = q.front(); q.pop();
		
		for (int neighbor : adj[node]) {
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				dist[neighbor] = dist[node] + 1;
				q.push(neighbor);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> adj(n);
	vector<int> zones(n);

	for (int i = 0; i < n; ++i) {
		cin >> zones[i];
	}

	char c;
	while (true) {
		cin >> c;
		if (c == 's') break;

		int a,b; cin >> a >> b;
		adj[a].push_back(b);
	}

	while (true) {
		cin >> c;
		if (c == 'q') break;
		int a,b;
		cin >> a >> b;
		if (c == 'b') {
			vector<bool> visited(n,false);
			vector<int> dist(n,-1);

			vector<bool> visited2(n,false);
			vector<int> dist2(n,-1);

			special(a,adj,visited,zones,dist);
			cout << dist[b];
			normal(a,adj,visited2,zones,dist2);
			(visited2[b]) ? cout << " Y\n" : cout << " N\n";

		}

		else {
			vector<bool> visited(n,false);
			vector<int> dist(n,-1);

			special(a,adj,visited,zones,dist);
			(visited[b]) ? cout << dist[b] << " Y\n" << endl : cout << dist[b] << " N\n";
		}

	}

	return 0;
}
