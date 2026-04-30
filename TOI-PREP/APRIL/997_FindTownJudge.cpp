#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

// take all input and put into adjacency list
// check for a node with no neighbors [ empty list ]
// check if everyone else trusts

class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		vector<vector<int>> adj(n);
		unordered_map<int,int> freq;
		
		for (const auto& edge : trust) {
			adj[edge[0]-1].push_back(edge[1]-1);
			freq[edge[1]-1]++;
		}

		for (int i = 0; i < n; ++i) {
			if (adj[i].empty()) {
				if (freq[i] == n-1) return i+1;
			}
		}

		return -1;
		
	}
};
