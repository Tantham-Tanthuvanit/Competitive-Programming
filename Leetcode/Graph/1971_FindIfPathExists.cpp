#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    #define pii pair<int,int>

    void dfsHelper(vector<vector<int>>& adj, vector<bool> &visited, int s, vector<int>&res) {
        visited[s] = true;
        res.push_back(s);

        for (int i : adj[s])
            if (visited[i] == false) {
                dfsHelper(adj, visited, i, res);
            }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        // build graph
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(n, false);
        vector<int> res;
        dfsHelper(graph, visited, source, res);
        return visited[destination];
    }
};
