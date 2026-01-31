#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>ans(n,0);

        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;

        for (int i = 0; i < n; i++) {
            ans[i] += movesToLeft;
            ballsToLeft += boxes[i]-'0';
            movesToLeft+=ballsToLeft;
        }

        for (int v = n-1; v >= 0; v--) {
            ans[v] += movesToRight;
            ballsToRight += boxes[v]-'0';
            movesToRight += ballsToRight;
        }

        return ans;
    }
};