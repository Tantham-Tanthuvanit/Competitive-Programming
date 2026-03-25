#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> adj(numCourses);
		vector<int> prereq(numCourses, 0);
		
		for (int i = 0; i < prerequisites.size(); i++) {
			adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
			prereq[prerequisites[i][0]]++;
		}

		queue<int> q;

		for (int i = 0; i < prereq.size(); ++i) {
			if (prereq[i] == 0) q.push(i);
		}

		vector<int> order;

		while (!q.empty()) {
			int node = q.front(); q.pop();
			order.push_back(node);

			for (int neighbor : adj[node]) {
				prereq[neighbor]--;
				if (prereq[neighbor] == 0)
					q.push(neighbor);
			}
		}

		if (order.size() != numCourses)
			return {};
		
		return order;
	}
};
