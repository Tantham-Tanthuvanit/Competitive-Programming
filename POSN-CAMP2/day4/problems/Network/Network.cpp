// ALGORITHM
// input vertecies
// connect vertex with weight
// display node islands 

#include <algorithm>
#include <iostream>
#include <string>
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
		adj[u].push_back(connection(v,w));

		nedges++;
	}

	void dfsHelper(int vertex, unordered_set<int>& visited, vector<int>& ans) {
		visited.insert(vertex);

		ans.push_back(vertex);

		vector<connection> neighbors = getConnections(vertex);


		sort(neighbors.begin(), neighbors.end(), [](const connection& a, const connection& b) {
			return a.vertex < b.vertex;
		});

		for (connection conn : neighbors) {
			if (visited.find(conn.vertex) == visited.end())
				dfsHelper(conn.vertex, visited, ans);
		}	
	}

	vector<int> dfs(int startVertex) {
		vector<int> ans;
		dfsHelper(startVertex, visited, ans);
		return ans;
	}
};

int main() {
	int nv; cin >> nv;
	Graph grph;


	int a,b;
	while (cin >> a >> b) {
			if (a == -1 && b == -1) break;
			if (a >= nv || b >= nv || a < 0 || b < 0) continue;
			grph.addEdge(a,b,1);
	}

	int networksNum = 0;


	vector<vector<int>> networks;
	
	for (int i = 0; i < nv; i++) {
		if (grph.visited.find(i) == grph.visited.end()) {
			networksNum++;
			vector<int> v = grph.dfs(i);
			sort(v.begin(), v.end());
			networks.push_back(v);
		}
	}

	cout << "Networks: " << networksNum << endl;
	for (int i = 0; i < networks.size(); i++) {
		cout << i + 1 << ":";
		for (int v : networks[i]) {
			cout << ' ' << v;
		}
		cout << endl;
	}

	return 0;
}
