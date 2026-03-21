#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int f, n_edges;
    if (!(cin >> f >> n_edges)) return 0;

    vector<int> existing_centers(f);
    for (int i = 0; i < f; i++) {
        cin >> existing_centers[i];
    }

    int max_node = 0;

    vector<pair<pair<int, int>, int>> edge_input(n_edges);
    for (int i = 0; i < n_edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge_input[i] = {{u, v}, w};
        max_node = max({max_node, u, v});
    }

    for (int c : existing_centers) {
        max_node = max(max_node, c);
    }

    vector<vector<pair<int, int>>> adj(max_node + 1);
    for (int i = 0; i < n_edges; i++) {
        int u = edge_input[i].first.first;
        int v = edge_input[i].first.second;
        int w = edge_input[i].second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> is_existing(max_node + 1, false);
    for (int c : existing_centers) {
        is_existing[c] = true;
    }

    auto run_dijkstra = [&](int start_node) {
        vector<int> dist(max_node + 1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[start_node] = 0;
        pq.push({0, start_node});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    };

    vector<vector<int>> all_pairs_dist(max_node + 1);
    for (int i = 1; i <= max_node; i++) {
        all_pairs_dist[i] = run_dijkstra(i);
    }

    vector<int> dist_to_existing(max_node + 1, INF);
    for (int i = 1; i <= max_node; i++) {
        for (int c : existing_centers) {
            dist_to_existing[i] = min(dist_to_existing[i], all_pairs_dist[c][i]);
        }
    }

    int best_center = -1;
    int min_max_dist = INF;

    for (int candidate = 1; candidate <= max_node; candidate++) {
        if (is_existing[candidate]) continue; 

        int current_max_dist = 0;

        for (int i = 1; i <= max_node; i++) {
            int d = min(dist_to_existing[i], all_pairs_dist[candidate][i]);

            current_max_dist = max(current_max_dist, d);
        }

        if (current_max_dist < min_max_dist) {
            min_max_dist = current_max_dist;
            best_center = candidate;
        } else if (current_max_dist == min_max_dist) {
            if (best_center == -1 || candidate < best_center) {
                best_center = candidate;
            }
        }
    }

    cout << best_center << "\n";

    return 0;
}
