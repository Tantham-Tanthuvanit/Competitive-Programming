#include <algorithm>
#include <cstddef>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

struct edge {
	int src, dest, weight;
	edge(int s, int d, int w) : src(s), dest(d), weight(w) {}

	bool operator<(const edge& other) const {
		return weight < other.weight;
	}
};

struct DSU {
	vector<int> parent;
	vector<int> rank;

	DSU(int n) {
		parent.resize(n + 1);
		rank.resize(n + 1, 0);

		for (int i = 0; i <= n; i++)
			parent[i] = i;
	}

	int find(int i) {
		if (parent[i] == i)
			return i;
		return parent[i] = find(parent[i]);
	}

	void unite(int i, int j) {
		int root_i = find(i);
		int root_j = find(j);

		if (root_i != root_j) {
			if (rank[root_i] < rank[root_j]) {
				parent[root_i] = root_j;
			} else if (rank[root_i] > rank[root_j]) {
				parent[root_j] = root_i;
			} else {
				parent[root_j] = root_i;
				rank[root_i]++;
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	if (!(cin >> n >> m)) return 0;

	vector<edge> edges;

	for (int i = 0; i < m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		edges.push_back(edge(u,v,w));
	}

	sort(edges.begin(), edges.end());

	DSU dsu(n);

	long long totalFlag = 0;
	int edges_used = 0;

	for (const edge& e : edges) {
		int root_src = dsu.find(e.src);
		int root_dest = dsu.find(e.dest);

		if (root_src != root_dest) {
			totalFlag += (e.weight - 1);
			dsu.unite(root_src, root_dest);
			edges_used++;

			if (edges_used == n - 1) {
				break;
			}
		}
	}

	cout << totalFlag;

	return 0;
}
