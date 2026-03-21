#include <climits>
#include <functional>
#include <iostream>
#include <iterator>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

#define pii pair<int,int>

struct edge {
	int vertex = 0;
	int distance = 0;

	edge(int v, int d) : vertex(v), distance(d) {}
};

struct Graph {
	int nverticies;
	int nedges;
	unordered_map<int, vector<edge>> adj;

	void addEdge(int start, int end, int weight) {
		if (adj.find(start) == adj.end()) { 
			adj[start] = vector<edge>();
		}
		if (adj.find(end) == adj.end()) { 
			adj[end] = vector<edge>();
		}
		adj[start].push_back(edge(end, weight));
		nedges++;
	}
};

unordered_map<int, int> dijkstra(Graph &g, int start) {
	unordered_map<int, int> distances;

	for (int i = 1; i <= g.nverticies; i++) {
		distances[i] = INT_MAX;
	}
	distances[start] = 0;

	// min heap
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	pq.push({0, start});

	// similar to BFS
	while (!pq.empty()) {
		auto [distance, currentVertex] = pq.top();
		pq.pop();

		// skip any outdated values
		if (distance > distances[currentVertex]) continue;

		// get and push adjacent nodes
		for (auto& e : g.adj[currentVertex]) {
			int nextVer = e.vertex;
			int distanceToNext = e.distance;

			if (distances[currentVertex] + distanceToNext < distances[nextVer]) {
				// update distances
				distances[nextVer] = distances[currentVertex] + distanceToNext;
				pq.push({distances[nextVer], nextVer});
			}
		}
	}

	return distances;
}

int main() {
	
	Graph graph;

	int nvertex = 0, startVertex = 0, endVertex = 0;
	cin >> nvertex >> startVertex >> endVertex;

	graph.nverticies = nvertex;

	int start = 0, end = 0, weight = 0;
	while (true) {

		cin >> start >> end;

		if (start == 0 && end == 0) break;

		cin >> weight;

		if (start < 1 || start > nvertex || start > 100 || end < 1 || end > nvertex || end > 100 || weight < 0) continue;

		graph.addEdge(start, end, weight);
	}

	unordered_map<int, int> distances = dijkstra(graph, startVertex);

	if (distances.find(endVertex) == distances.end() || distances[endVertex] == INT_MAX) cout << -1;
	else cout << distances[endVertex];

	return 0;
}
