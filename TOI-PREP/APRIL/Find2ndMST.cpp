#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> fathers(100);

int find(int x) {
	if (fathers[x] != x) fathers[x] = find(fathers[x]);
	return fathers[x];
}

void unite(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) fathers[fx] = fy;
}

// DFS to find max edge on a path
int dfs(int src, int target, vector<vector<pair<int,int>>>& adj, vector<bool>& visited, int maxweight) {
	if (src == target) return maxweight;
	visited[src] = true;

	for (auto& [dest,edge] : adj[src]) {
		if (!visited[dest]) {
			int res = dfs(dest,target,adj,visited,max(maxweight,edge));
			if (res != -1) return res;
		}
	}
	return -1;
}

int main() {
	speed
	for (int i = 0; i < fathers.size(); ++i) fathers[i] = i;

	int n,m,a,b,w;
	cin >> n >> m;

	vector<tuple<int,int,int>> edges;

	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> w;
		edges.push_back({w,a,b});
	}

	// sort the edges
	sort(edges.begin(), edges.end());

	int mst_weight = 0, mst_edges =  0;

	vector<bool> usedEdges(m,false); // track used edges in mst
	vector<vector<pair<int,int>>> mst_adj(n); // graph for mst;
	
	// build mst
	for (int i = 0; i < m && mst_edges < n-1; ++i) {
		auto [weight,u,v] = edges[i];

		if (find(u) != find(v)) {
			unite(u,v);
			mst_weight += weight;
			mst_edges++;
			usedEdges[i] = true;

			// build adjacency list for mst
			mst_adj[u].push_back({v,weight});
			mst_adj[v].push_back({u,weight});
		}
	}

	// find 2nd mst
	int second_mst = INT_MAX;

	for (int i = 0; i < m; ++i) {
		if (usedEdges[i]) continue; // skip edges that are already int the mst

		auto [weight, u, v] = edges[i];

		vector<bool> vis(n,false);
		int max_edge = dfs(u,v,mst_adj,vis,0);

		if (max_edge == -1) continue;

		// add the edge and remove the max edge of the mst;
		int candidate = mst_weight + weight - max_edge;
		
		if (candidate > mst_weight) second_mst = min(second_mst, candidate);
	}

	return 0;
}
