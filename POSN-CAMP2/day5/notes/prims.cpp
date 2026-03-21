#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <type_traits>
#include <unordered_map>
#include <vector>

using namespace std;

#define pii pair<int,int>

struct edge {
	int vertex;
	int weight;

	edge(int v, int w) : vertex(v), weight(w) {}
};

struct Graph {
	int nverticies = 0;
	int nedges = 0;
	unordered_map<int, vector<edge>> adj;

	void addEdge(int start, int end, int weight) {
		adj[start].push_back(edge(end, weight));
		adj[end].push_back(edge(start, weight));
		nedges++;
	}
};

int prim(Graph& g, int start_vertex) {
	unordered_map<int, bool> visited;

	// min head {distance, vertex};
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0,start_vertex});

	int totalCost = 0;

	while (!pq.empty()) {
		auto [weight, currentVert] = pq.top();
		pq.pop();

		if (visited[currentVert]) continue;

		visited[currentVert] = true;
		totalCost += weight;

		for (auto& e : g.adj[currentVert]) {
			int nextVert = e.vertex;
			int weight = e.weight;

			if (!visited[nextVert]) {
				pq.push({weight, nextVert});
			}
		}
	}

	return totalCost;
}

int main() {

	Graph graph;
	int n = 0, m = 0;
	cin >> n >> m;

	graph.nverticies = n;
	int s = 0, e = 0, w = 0;

	while (m--) {
		cin >> s >> e >> w;

		if (s > n || e > n) continue;
		graph.addEdge(s, e, w);
	}

	int target = 0; cin >> target;
	cout << prim(graph, target);
	

	return 0;

}
