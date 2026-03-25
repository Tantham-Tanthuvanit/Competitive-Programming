#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool cycleDetection(vector<vector<int>>& adj, vector<int>& state, int src) {
        if (state[src] == 1) return true;
        if (state[src] == 2) return false;

        state[src] = 1;

        for (int i : adj[src])
            if (cycleDetection(adj,state,i)) return true;
        
        state[src] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) return true;

        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            // add prerequisite and the course
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            // start dfs if node not found
            if (state[i] == 0) {
                if (cycleDetection(adj,state,i)) return false;
            }
        }

        return true;
    }
};