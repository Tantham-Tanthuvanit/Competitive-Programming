// solved on mon april 20th 2026 at 11:30
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define speed                                                                  \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);
typedef vector<vector<pair<int, int>>> adjacency_list;

int main() {
  int n, ed, k;
  cin >> n >> ed >> k;
  adjacency_list adj(n);

  while (ed--) {
    int s, e, w;
    cin >> s >> e >> w;
    adj[s].push_back({e, w});
    adj[e].push_back({s, w});
  }

  int mx = INT_MIN;

  for (int src = 0; src < adj.size(); ++src) {
    vector<int> distance(n, INT_MAX);
    unordered_map<int, bool> visited;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    distance[src] = 0;
    visited[src] = true;
    pq.push({0, src});

    while (!pq.empty()) {
      int cur = pq.top().second;
      int distcur = pq.top().first;
      pq.pop();

      if (distcur > distance[cur])
        continue;

	  for (const auto& [dest, dist] : adj[cur]) {
		  if (distance[dest] > distance[cur] + dist) {
			  distance[dest] = distance[cur] + dist;
			  pq.push({distance[dest],dest});
		  }
	  }
	}

	int cnt = 0;
	for (int i = 0; i < distance.size(); ++i) {
		if (i == src) continue;
		if (distance[i] <= k) cnt++;
	}
	mx = max(cnt,mx);

  }

  cout << mx << endl;

  return 0;
}
