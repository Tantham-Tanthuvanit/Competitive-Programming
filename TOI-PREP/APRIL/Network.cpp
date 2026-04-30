// solved on fri april 17th 2026 at 12:43
#include <bits/stdc++.h>
#include <endian.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

void dfs(vector<int>& network, int src, vector<vector<int>>& adj, vector<bool>& visited) {
	if (visited[src]) return;
	visited[src] = true;
	network.push_back(src);
	for (auto& neighbor : adj[src]) {
		dfs(network, neighbor, adj, visited);
	}
}

int main() {
	speed

	int n; cin >> n;
	vector<vector<int>> adj(n);

	while (true) {
		int a,b; cin >> a >> b;
		if (a == -1 && b == -1) break;
		if (a >= n || b >= n) continue;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<vector<int>> networks;
	vector<bool> visited(n);

	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			vector<int> net;
			dfs(net, i, adj, visited);
			networks.push_back(net);
		} 
	}

	cout << "Networks: " << networks.size() << endl;

	for (int i = 0; i < networks.size(); ++i) {
		sort(networks[i].begin(), networks[i].end());
		cout << i+1 << ": ";
		for (int v = 0; v < networks[i].size(); ++v) cout << networks[i][v] << ' ';
		cout << endl;
	}
	
	return 0;
}
