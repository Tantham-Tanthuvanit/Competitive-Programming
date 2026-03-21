#include <climits>
#include <functional>
#include <queue>
#include <type_traits>
#include <vector>
#include <unordered_map>

using namespace std;

#define pii pair<int,int>

struct edge {
	int vertex;
	int weight;

	edge(int v, int w) : vertex(v), weight(w) {}
};

struct Graph {
	int nvert;
	int nedge;
	unordered_map<int, vector<edge>> adj;

	void addEdge(int from, int to, int weight) {
		if (adj.find(from) == adj.end()) nvert++;
		if (adj.find(to) == adj.end()) nvert++;
		adj[from].push_back(edge(to, weight));
		nedge++;
	}
};

struct matrixGraph {
	int nvert;
	vector<vector<int>> adj;
};

unordered_map<int,int> dijkstra(Graph &g, int start) {
	unordered_map<int, int> distances;

	// initialise list
	for (auto& p : g.adj)
		distances[p.first] = INT_MAX;
	distances[start] = 0;

	// min heap {distance, vertex};
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	pq.push({0, start});
	
	// similar to BFS
	while (!pq.empty()) {
		auto [distance,currentVertex] = pq.top();
		pq.pop();

		// skip outdated vals;
		if (distance > distances[currentVertex]) continue;

		// get and push adjacent nodes
		for (auto& e : g.adj[currentVertex]) {
			int nextVert = e.vertex;
			int distanceToNext = e.weight;

			// check if the distance from start to current vertex AND the distance to the next vertex is less than the current
			// recorded distance for nextVertex
			if (distances[currentVertex] + distanceToNext < distances[nextVert]) {
				// update
				distances[nextVert] = distances[currentVertex] + distanceToNext;
				// push back into pq
				pq.push({distances[nextVert], nextVert});
			}
		}
	}

	return distances;

}

int prim(Graph &g, int start) {
	unordered_map<int, bool> visited;

	// min heap {distance, vertex};
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	pq.push({0, start});

	int totalCost = 0;
	
	// similar to BFS
	while (!pq.empty()) {
		auto [weight,currentVertex] = pq.top();
		pq.pop();

		// skip outdated vals;
		if (visited[currentVertex]) continue;

		visited[currentVertex] = true;
		totalCost += weight;

		// get and push adjacent nodes
		for (auto& e : g.adj[currentVertex]) {
			int nextVert = e.vertex;
			int weight = e.weight;

			// check if the distance from start to current vertex AND the distance to the next vertex is less than the current
			// recorded distance for nextVertex
			if (!visited[nextVert]) {
				pq.push({weight, nextVert});
			}
		}
	}

	return totalCost;

}
vector<vector<int>> FloydWarshall(matrixGraph graph) {
	int n = graph.nvert;

	vector<vector<int>> dist = graph.adj;

	for (int i = 0; i < n; i++) {
		dist[i][i] = 0;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	return dist;
}


int main() {

	Graph graph;

	graph.addEdge(1, 2, 4);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 3, 5);
    graph.addEdge(2, 4, 10);
    graph.addEdge(3, 5, 3);
    graph.addEdge(5, 4, 4);
    graph.addEdge(4, 6, 11);

	return 0;

}
