// solved on thu april 21st 2026 at 13:42
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef pair<int,int> pii;
typedef tuple<int,int,int> tup;

vector<int> root;

int getRoot(int x) {
	if (root[x] == x) return x;
	return getRoot(root[x]);
}

void unite(int x, int y) {
	int fx = getRoot(x);
	int fy = getRoot(y);
	root[fx] = fy;
}

int main() {
	speed

	int n,e; cin >> n >> e;

	root.resize(n+1);
	for (int i = 0; i < root.size(); ++i) root[i] = i;

	vector<tup> edges;
	
	for (int i = 0; i < e; ++i) {
		int a,b,w; cin >> a >> b >> w;
		edges.push_back({w,a,b});
	}

	sort(edges.begin(), edges.end());

	int mst_weight = 0, mst_edges = 0;

	for (int i = 0; i < e && mst_edges < n-1; ++i) {
		auto [weight,src,dest] = edges[i];

		if (getRoot(src) != getRoot(dest)) {
			unite(src, dest);
			mst_weight += weight;
			mst_edges++;
		}
	}

	cout << mst_weight - n + 1;
	
	return 0;
}
