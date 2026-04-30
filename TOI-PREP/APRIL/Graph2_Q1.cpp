// solved on sat april 18th 2026 at 19:20
#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef pair<int,int> pii;
typedef vector<vector<pair<int,int>>> adjacency_list;

int main() {
	int n,start,end; cin >> n >> start >> end;

	adjacency_list adj(n+1);

	while (true) {
		int a,b; cin >> a >> b;
		if (a + b == 0) break;
		if (a > n || b > n) continue;
		int w; cin >> w;
		// add to adjacency_list;
		adj[a].push_back({w,b});
		adj[b].push_back({w,a});
	}

	vector<int> distance(n+1,INT_MAX);
	unordered_map<int,bool> visited;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	distance[start] = 0;
	visited[start] = true;
	pq.push({0,start});

	while (!pq.empty()) {
		pii top = pq.top(); pq.pop();
		int src = top.second;
		
		if (top.first > distance[src]) continue;
	
		for (const auto& neigh : adj[src]) {
			int dest = neigh.second;
			int dist = neigh.first;

			if (distance[dest] > distance[src] + dist) {
				distance[dest] = distance[src] + dist;
				pq.push({distance[dest],dest});
			}
		}

	}

	distance[end] == INT_MAX ? cout << -1 : cout << distance[end];

	return 0;
}
