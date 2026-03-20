#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
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
    unordered_set<int, int> distance;

    void addEdge(int v, int u, int w) {
        //if (adj.find(v) == adj.end()) nvert++;
        //if (adj.find(u) == adj.end()) nvert++;

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

int main() {
	int n; cin >> n;
	Graph graph;
	graph.nvert = n;

	while (true) {
		int a, b;
		cin >> a >> b;

		if (a > n-1 || b > n-1) continue;

		if (a == -1 && b == -1) break;
		else graph.addEdge(a, b, 1);

	}

	int x; cin >> x;

	vector<int> visited = graph.bfs(x);

	for (int i = 0; i < visited.size(); i++) {
		cout << i << ':' << visited[i] << endl;
	}

    return 0;
}
