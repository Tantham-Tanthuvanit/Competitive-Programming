#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

// replace with hashmap when numbers are not continuous and they get riddiculously large
vector<int> fathers(100);
unordered_map<int,int> fathers2;

int find(int x) {
	if (fathers[x] == x) return x;
	return find(fathers[x]);
}

int hashMapFind(int x) {
	if (fathers2.find(x) == fathers2.end()) fathers2[x] = x;
	if (fathers2[x] != x) fathers2[x] = hashMapFind(fathers2[x]);
	return fathers2[x];
}

void unite(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	fathers[fx] = fy;
}

int main() {
	// initialize fathers for the disjointed sets
	for (int i = 0; i < fathers.size(); ++i)
		fathers[i] = i;

	int n,m,a,b,w;
	vector<pair<int,pair<int,int>>> edges;
	// load input
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> w;
		edges.push_back({w,{a,b}});
	}

	// everything under here is kuskals algorithm
	
	int mst_weight = 0, mst_edges = 0;
	int mst_nextIndex = 0;
	// STEP 1 [ SORT EDGES ]
	sort(edges.begin(), edges.end());
	// STEP 2 - 3
	while ((mst_edges < n - 1) || (mst_nextIndex < m)) {
		// break the edge into 3 initigers
		int src = edges[mst_nextIndex].second.first;
		int dest = edges[mst_nextIndex].second.second;
		int weight = edges[mst_nextIndex].first;
		// check if edge is ok to be included into mst
		// if a and b are in different trees
		if (find(a) != find(b)) {
			// found 2 trees then connect the edges
			unite(src,dest);
			mst_weight += w;
			cout << src << ' '<< dest << ' ' << weight << endl;
			mst_edges++;
		}
		mst_nextIndex++;
	}

	cout << "TOTAL WEIGHT OF MST IS "<< mst_weight << endl;

	return 0;
}
