#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int MAXV = 1000;

/*
USING ARRAYS
struct graph {
	int edges[MAXV][MAXV] = {};
	int degrees[MAXV] = {};
	int nverticies = 0;
	int nedges = 0;
};
*/

struct connection {
	int vertex;
	int weight;

	connection(int vert, int w) {
		vertex = vert;
		weight = w;
	}
};

// non weighted
struct graph {
	int nverticies = 0;
	int nedges = 0;
	unordered_map<int, vector<int>> adj;

	int getDegrees(int v) {
		return adj[v].size();
	}

	const vector<int>& getConnections(int v) {
		static vector<int> empty;
		if (adj.find(v) == adj.end()) return empty;
		return adj[v];
	}

	void addEdge(int u, int v) {
		if (adj.find(u) == adj.end()) nverticies++;
		if (adj.find(v) == adj.end()) nverticies++;

		adj[u].push_back(v);
		adj[v].push_back(u);

		nedges++;
	}

};

// weighted
struct weightedGraph {
	int nverticies = 0;
	int nedges = 0;
	unordered_map<int, vector<connection>> adj;

	int getDegrees(int v) {
		return adj[v].size();
	}

	const vector<connection>& getConnections(int v) {
		static vector<connection> empty;
		if (adj.find(v) == adj.end()) return empty;
		return adj[v];
	}

	void addEdge(int u, int v, int w) {
		if (adj.find(u) == adj.end()) nverticies++;
		if (adj.find(v) == adj.end()) nverticies++;

		adj[u].push_back(connection(v, w));
		adj[v].push_back(connection(u, w));

		nedges++;
	}

};

int main() {

return 0;
}
