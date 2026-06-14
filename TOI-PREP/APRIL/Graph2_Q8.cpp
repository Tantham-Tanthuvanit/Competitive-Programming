// use modified dijkstra to find the maximum bottleneck capacity to reach u
// new_cap = min(best[u], edge_weight)

#include <bits/stdc++.h>
#include <iterator>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef pair<int,int> pii;

int main() {
	speed

	int n,m; cin >> n >> m;
	int start, dest, p;
	vector<vector<pii>> adjacency(n+1);

	for (int i = 0; i < m; ++i) {
		int s,d,w; cin >> s >> d >> w;
		adjacency[s].push_back({d,w});
		adjacency[d].push_back({s,w});
	}

	cin >> start >> dest >> p;
	

	vector<int> minEdge(n+1,0);
	priority_queue<pii,vector<pii>,less<pii>> pq;
	minEdge[start] = INT_MAX;
	pq.push({INT_MAX,start});

	while (!pq.empty()) {
		pii top = pq.top(); pq.pop();
		int src = top.second;
		int edge = top.first;

		if (edge < minEdge[src]) continue;

		for (const auto& neigh : adjacency[src]) {
			int v = neigh.first;
			int e = neigh.second;

			if (min(minEdge[src],e) > minEdge[v]) {
				minEdge[v] = min(minEdge[src],e);
				pq.push({min(minEdge[src],e),v});
			}
		}
	}

	cout << ceil((double)p / (minEdge[dest] - 1)) << endl;

	return 0;
}
