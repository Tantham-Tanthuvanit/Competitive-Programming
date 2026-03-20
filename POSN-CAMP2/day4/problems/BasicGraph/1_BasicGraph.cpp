#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

struct connection {
	int vertex;
	int weight;

	connection(int vert, int w) {
		vertex = vert;
		weight = w;
	}
};

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

		nedges++;
	}
	
	//----------[ BFS ]----------------------//
	void bfs(int startVertex) {
		unordered_set<int> visited;
		queue<int> q;

		visited.insert(startVertex);
		q.push(startVertex);

		while (!q.empty()) {
			int current = q.front();
			q.pop();
			cout << current << ' ';

			vector<connection> neighbors = getConnections(current);

			// sort neighbors
			sort(neighbors.begin(), neighbors.end(), [](const connection& a, const connection& b) {
					return a.vertex < b.vertex;
			});

			// call get Connections directly
			for (const connection& conn : neighbors) {
				if (visited.find(conn.vertex) == visited.end()) {
					visited.insert(conn.vertex);
					q.push(conn.vertex);
				}
			}
		}

		cout << endl;
	}

	//----------------------------[ DFS ]------------------------------------//

	void dfsHelper(int vertex, unordered_set<int>& visited) {
		visited.insert(vertex);
		cout << vertex << ' ';

		vector<connection> neighbors = getConnections(vertex);

		// sort neighbors by size (smaller to larger)
		sort(neighbors.begin(), neighbors.end(), 
		[](const connection& a, const connection& b) {
				return a.vertex < b.vertex;
				});

		for (const connection& conn : neighbors) {
			if (visited.find(conn.vertex) == visited.end()) {
				dfsHelper(conn.vertex, visited);
			}
		}
	}

	void dfs(int startVertex) {
		unordered_set<int> visited;
		dfsHelper(startVertex, visited);
		cout << endl;
	}

};

int main() {

	int nvert; cin >> nvert;
	weightedGraph graph;

	// 1st loop [ adding vertecies ]
	while (true) {

		char cmd; cin >> cmd;

		if (cmd == 'e') {
			int start, end, weight;
			cin >> start >> end >> weight;

			if (weight == 0) continue;

			graph.addEdge(start, end, weight);
		}
		else break;
		
	}

	// 2nd loop [ showing values ]
	while (true) {

		char cmd; cin >> cmd;

		if (cmd == 'd') {
			int vert; cin >> vert;
			graph.dfs(vert);
			continue;
		}

		if (cmd == 'b') {
			int vert; cin >> vert;
			graph.bfs(vert);
			continue;
		}

		else {
			break;
		}

	}
	
	return 0;
}
