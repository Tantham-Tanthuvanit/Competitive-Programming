#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct connection {
	int vertex = 0;
	int weight = 0;

	connection(int v, int w) : vertex(v), weight(w) {}
};

struct Graph {
	int nvert = 0;
	int nedge = 0;
	unordered_map<int, vector<connection>> adj;
	unordered_set<int> distance;

	void addEdge(int v, int u, int w) {

		adj[v].push_back(connection(u,w));
		adj[u].push_back(connection(v,w));

		nedge++;

	}

	vector<connection>& getNeighbors(int vertex) { return adj[vertex]; }

	vector<int> bfs(int startVertex) {
		vector<int> distances(nvert, -1);
		unordered_set<int> visited;
		queue<int> q;

		q.push(startVertex);
		visited.insert(startVertex);
		distances[startVertex] = 0;

		while (!q.empty()) {
			int current = q.front();
			q.pop();

			vector<connection> neighbors = getNeighbors(current);

			for (const connection& con : neighbors) {
				if (visited.find(con.vertex) == visited.end()) {
					visited.insert(con.vertex);
					distances[con.vertex] = distances[current] + 1;
					q.push(con.vertex);
				}
			}
		}

		return distances;

	}
};

struct g {
	int v;
	int u;
	g(int x,int c) : v(x), u(c) {}
};

int main() {
	int n; cin >> n;
	vector<g> edges;

	Graph graph;
	graph.nvert = n;
	int a,b;

	while (cin >> a >> b) {
		if (a == -1 && b == -1) break;

		edges.push_back({a,b});
	}

	int curr, zom, bunk;
	if (!(cin >> curr >> zom >> bunk)) return 0;

	for (g edge : edges) {
		if (edge.v == zom || edge.u == zom) continue;
		
		graph.addEdge(edge.u, edge.v, 1);
	}

	cout << graph.bfs(curr)[bunk];

	return 0;
}
