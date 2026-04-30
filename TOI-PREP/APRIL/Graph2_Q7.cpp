#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
	speed

	int centerN, edges;
	vector<bool> exists(edges,false);
	vector<vector<pair<int,int>>> adj(edges);

	cin >> centerN >> edges;

	for (int i = 0; i < centerN; ++i) {
		int x; cin >> x;
		exists[x-1] = true;
	}

	for (int i = 0; i < edges; ++i) {
		int a,b,w; cin >> a >> b >> w;

		adj[a-1].push_back({b-1,w});
	}

	int minNode = 0;
	int mn = INT_MIN;

	for (int src = 0; src < exists.size(); ++src) {
		if (exists[src]) continue;

		vector<int> distance(edges,INT_MAX);
		unordered_map<int,bool> visited;
		priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
		distance[src] = 0;
		visited[src] = true;
		pq.push({0,src});

		while (!pq.empty()) {
			int cur = pq.top().second;
			int dist = pq.top().first;
			pq.pop();

			if (dist > distance[cur]) continue;

			for (const auto& [dest, dist] : adj[cur]) {
				if (distance[dest] > distance[cur] + dist) {
					distance[dest] = distance[cur] + dest;
					pq.push({distance[dest],dest});
				}
			}
		}

		int mx = INT_MIN;
		int mxNode;

		for (int i = 0; i < distance.size(); ++i) {
			if (distance[i] > mx && src != i) {
				mx = distance[i];
				mxNode = i;
			}
		}

		if (mn > mx) {
			mn = mx;
			minNode = mxNode;
		}

	}

	cout << mn + 1 << endl;

	return 0;
}
