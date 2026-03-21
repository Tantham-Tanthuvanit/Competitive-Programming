#include <algorithm>
#include <climits>
#include <ios>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void FloydWarshall(vector<vector<int>>& graph) {
	int n = graph.size();

	for (int i = 0; i < n; i++) {
		graph[i][i] = 0;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int v = 0; v < n; v++) {
				if (graph[i][k] != INT_MAX && graph[k][v] != INT_MAX) {
					graph[i][v] = min(graph[i][v], graph[i][k] + graph[k][v]);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);

	int nvert = 0, nedge = 0, threshhold = 0;
	cin >> nvert >> nedge >> threshhold;

	vector<vector<int>> adj(nvert, vector<int>(nvert, INT_MAX));

	int from = 0, to = 0, distance = 0;
	while (nedge--) {
		cin >> from >> to >> distance;
		if (from < 0 || from >= nvert || to < 0 || to >= nvert) continue;
		adj[from][to] = distance;
		adj[to][from] = distance;
	}

	FloydWarshall(adj);

	int best = -1;
	int minCount = INT_MAX;

	for (int i = 0; i < adj.size(); i++) {
		int count = 0;
		for (int v = 0; v < adj.size(); v++) {
			if (i != v && adj[i][v] <= threshhold)
				count++;
		}
		//cout << i << " : " << count << "min count : " << minCount << "best : " << best << endl;
		if (count == 0) continue;
		else if (count < minCount || (count == minCount && i > best)) {
			minCount = count;
			best = i;
		}
	}

	cout << best;

	return 0;
}
