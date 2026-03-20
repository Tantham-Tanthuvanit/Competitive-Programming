#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct connection {
	int vertex;
	int weight;

	connection(int v, int w) : vertex(v), weight(w) {}
};

struct Graph {
	int nvert = 0;
	int nedge = 0;
	unordered_map<int, vector<connection>> adj;

	void addEdges(int v, int u, int w) {
		if (adj.find(v) == adj.end()) nvert++;
		if (adj.find(u) == adj.end()) nvert++;
		
		adj[v].push_back(connection(u,w));
		adj[u].push_back(connection(v,w));

		nedge++;
	}

	const vector<connection>& getConnections(int vertex) {
		return adj[vertex];
	}

	// cycle detection
	bool dfsHelper(int vertex, int parent, unordered_set<int>& visited) {
		visited.insert(vertex);

		vector<connection> neighbors = getConnections(vertex);

		for (const connection& conn : neighbors) {

			int neighbor = conn.vertex;

			if (visited.find(neighbor) == visited.end()) {
				if (dfsHelper(neighbor, vertex, visited)) return true; }
			else if (neighbor != parent) return true;
		}

		return false;

	}

	bool dfs(int startVertex) {
		unordered_set<int> visited;
		return dfsHelper(startVertex, -1, visited);
	}

};

int main() {

	int nv; cin >> nv;
	Graph graph;

	while (true) {
		char cmd; cin >> cmd;

		if (cmd == 'e') {
			int start, end, weight;
			cin >> start >> end >> weight;

			graph.addEdges(start, end, weight);
		}
		else break;
	}

	if (graph.dfs(0)) cout << "Cycle";
	else cout << "No Cycle";

	return 0;

}
