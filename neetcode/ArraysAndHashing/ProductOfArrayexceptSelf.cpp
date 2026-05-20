#include "config.h"

class Solution {
	public:
		vector<int> productExceptSelf(vector<int>& nums) {
			vector<int> ans;
			for (int i = 0; i < nums.size(); ++i) {
				int val = 1;
				for (int v = 0; v < nums.size(); ++v) {
					if (i == v) continue;
					val *= nums[v];
				}
				ans.push_back(val);
			}
			return ans;
		}
};
