#include "config.h"

class Solution {
	public:
		vector<int> topKFrequent(vector<int>& nums, int k) {
			unordered_map<int,int> freq;
			for (int n : nums) freq[n]++;

			vector<pair<int,int>> pairs(freq.begin(),freq.end());
			sort(pairs.begin(), pairs.end(), [](auto& a, auto& b) {
					return a.second > b.second;
					});

			vector<int> res;
			for (int i = 0; i < k; i++) {
				res.push_back(pairs[i].first);
			}

			return res;
		}
};
