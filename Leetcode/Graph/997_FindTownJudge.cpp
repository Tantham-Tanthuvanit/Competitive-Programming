#include <bits/stdc++.h>

using namespace std;

#define SHIT ios_base::sync_with_stdio(0);cin.tie(nullptr);

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        SHIT

        if (n == 2 && trust.empty()) return -1;
        if (trust.empty()) return n;

        vector<vector<int>> adj(n+1);
        vector<int> freq(n+1,0);
        
        for (int i = 0; i < trust.size(); i++) {
            adj[trust[i][0]].push_back(trust[i][1]);
            freq[trust[i][1]]++;
        }

        for (int i = 0; i < adj.size(); i++) {
            if (adj[i].empty() && freq[i] == n-1) {
                return i;
            }
        }

        return -1;
    }
};