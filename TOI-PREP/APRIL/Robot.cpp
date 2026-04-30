#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define speed ios_base::sync_with_stdio(false);
typedef pair<int,int> pii;

int main() {
	int r,c; cin >> r >> c;
	map<pii, vector<pii>> adj;
	vector<vector<char>> grid(r,vector<char>(c));

	for (int i = 0; i < r; ++i)
		for (int v = 0; v < c; ++v)
			cin >> grid[i][v];

	int dr[] = {-1,1,0,0};
	int dc[] = {0,0,-1,1};

	pii start,end;

	for (int i = 0; i < r; ++i) {
		for (int v = 0; v < c; ++v) {
			if (grid[i][v] == 'S') start = {i,v};
			if (grid[i][v] == 'E') end = {i,v};
			if (grid[i][v] == '#') continue;
			for (int k = 0; k < 4; ++k) {
				int nr = i + dr[k];
				int nc = v + dc[k];

				if (nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nr][nc] != '#')
					adj[{i,v}].push_back({nr,nc});
			}
		}
	}

	map<pii,bool> visited;
	map<pii,int> dist;
	queue<pii> q;

	visited[start] = true;
	dist[start] = 0;
	q.push(start);

	while (!q.empty()) {
		pii cur = q.front(); q.pop();

		for (auto& neighbor : adj[cur]) {
			if (visited[neighbor]) continue;
			visited[neighbor] = true;
			dist[neighbor] = dist[cur] + 1;
			q.push(neighbor);
		}
	}

	dist[end] == 0 ? cout << -1 : cout << dist[end];

	return 0;
}
