// ALGORITHM
// input vertecies
// connect vertex with weight
// display node islands 

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct connection {
	int vertex;
	int weight;

	connection(int v, int w) : vertex(v), weight(w) {}
};

struct Graph {
	int nvert = 0;
	int nedges = 0;
	unordered_map<int, vector<connection>> adj;
	unordered_set<int> visited;

	const vector<connection>& getConnections(int v) {
		static vector<connection> empty;
		if (adj.find(v) == adj.end()) return empty;
		return adj[v];
		
	}

	void addEdge(int v, int u, int w) {
		if (adj.find(v) == adj.end()) nvert++;
		if (adj.find(u) == adj.end()) nvert++;

		adj[v].push_back(connection(u,w));

		nedges++;
	}

	void dfsHelper(int vertex, unordered_set<int>& visited) {
		visited.insert(vertex);

		cout << vertex << ' ';

		vector<connection> neighbors = getConnections(vertex);


		sort(neighbors.begin(), neighbors.end(), [](const connection& a, const connection& b) {
			return a.vertex < b.vertex;
		});

		for (connection conn : neighbors) {
			if (visited.find(conn.vertex) == visited.end())
				dfsHelper(conn.vertex, visited);
		}	
	}

	void dfs(int startVertex) {
		dfsHelper(startVertex, visited);
		cout << endl;
	}
};

int main() {
	int nv; cin >> nv;
	Graph grph;

	while (true) {
		char cmd; cin >> cmd;

		// enter in edges
		if (cmd == 'e') {
			int start, end, weight;
			cin >> start >> end >> weight;

			grph.addEdge(start, end, weight);
		}

		// s
		else break;

	}
	
	for (int i = 0; i < nv; i++) {
		if (grph.visited.find(i) == grph.visited.end())
			grph.dfs(i);
	}

	return 0;
}
