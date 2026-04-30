// solved on thu april 16th 2026 at 11:00
#include <bits/stdc++.h>
#include <pthread.h>
#include <vector>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef vector<vector<int>> adjacency_list;

// CYCLE DETECTION CODE
bool dfs(int src, adjacency_list& adj, vector<int>& state) {
	state[src] = 1; // mark node as being explored
	
	for (int nei : adj[src]) {
		// if next node is clear then continue exploring
		if (state[nei] == 0) {
			if (dfs(nei,adj,state)) return true;
		}
		// found cycle
		else if (state[nei] == 1) {
			return true;
		}
	}

	state[src] = 2; // mark node path as completely explored;
	return false;
}

int main() {
	speed

	int n; cin >> n;
	adjacency_list adj(n);

	while (true) {
		char cmd; cin >> cmd;
		if (cmd == 's') break;
		int a,b,w; cin >> a >> b >> w;
		adj[a].push_back(b);
	}

	vector<int> state(n);
	if (dfs(0, adj, state)) cout << "Cycle";
	else cout << "No Cycle";

	return 0;
}
