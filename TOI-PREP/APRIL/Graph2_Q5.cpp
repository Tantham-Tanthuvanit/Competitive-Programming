// solved on thu april 21st 2026 at 13:28
#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef pair<int,int> pii;

vector<int> ancestors;

int find(int x) {
	if (ancestors[x] != x) ancestors[x] = find(ancestors[x]);
	return ancestors[x];
}

void unite(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) ancestors[fx] = fy;
}
int dfs(int src, int target, vector<vector<pii>>& adj, vector<bool>& visited, int maxweight) {
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

	int n,e; cin >> n >> e;
	vector<tuple<int,int,int>> edges;

	ancestors.resize(n+1);
	for (int i = 1; i <= n; ++i) ancestors[i] = i;

	// input edges
	for (int i = 0; i < e; ++i) {
		int a,b,w; cin >> a >> b >> w;
		edges.push_back({a,b,w});
	}

	sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
			return get<2>(a) < get<2>(b);
			});

	int mst_weight = 0, mst_edges = 0;

	vector<bool> usedEdges(e,false); // track edges that have been used inside the mst
	vector<vector<pair<int,int>>> mst_adj(n + 1);

	// build the mst
	for (int i = 0; i < e && mst_edges < n-1; ++i) {
		auto [u,v,weight] = edges[i];

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

	int second_mst = INT_MAX;

	for (int i = 0; i < e; ++i) {
		if (usedEdges[i]) continue;

		auto [u,v,weight] = edges[i];

		vector<bool> visited(n+1,false);
		int max_edge = dfs(u,v,mst_adj,visited,0);

		if (max_edge == -1) continue;

		// add the edge and remove max edge of mst
		int candidate = mst_weight + weight - max_edge;
		if (candidate > mst_weight) second_mst = min(second_mst,candidate);
	}

	cout << mst_weight << ' ' << second_mst << endl;

	return 0;
}
