#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
	int findPermutationDifference(string s, string t) {
		unordered_map<char, int> mp;
		for (int i = 0; i < s.size(); i++) {
			mp[s[i]] = i;
		}
		
		int ans = 0;

		for (int v = 0; v < s.size(); v++)
			ans += abs(mp[t[v]] - v);
		
		return ans;

	}
};
