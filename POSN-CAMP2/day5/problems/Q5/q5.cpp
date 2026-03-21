#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, weight, id;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DSU {
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
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
            return true; // Successfully connected
        }
        return false; // Already connected
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w, i});
    }

    sort(edges.begin(), edges.end());

    DSU dsu_main(n);
    int mst1_weight = 0;
    int edges_used = 0;
    vector<int> mst_edge_ids;

    for (const auto& edge : edges) {
        if (dsu_main.unite(edge.u, edge.v)) {
            mst1_weight += edge.weight;
            mst_edge_ids.push_back(edge.id);
            edges_used++;

            if (edges_used == n - 1) break;
        }
    }

    int mst2_weight = INF;

    for (int ignored_edge_id : mst_edge_ids) {
        DSU dsu_backup(n);
        int current_weight = 0;
        int current_edges_used = 0;

        for (const auto& edge : edges) {
            if (edge.id == ignored_edge_id) continue;

            if (dsu_backup.unite(edge.u, edge.v)) {
                current_weight += edge.weight;
                current_edges_used++;

                if (current_edges_used == n - 1) break;
            }
        }

        if (current_edges_used == n - 1) {
            mst2_weight = min(mst2_weight, current_weight);
        }
    }

    cout << mst1_weight << " " << mst2_weight << "\n";

    return 0;
}
