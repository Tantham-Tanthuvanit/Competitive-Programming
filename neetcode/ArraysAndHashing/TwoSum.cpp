#include "config.h"

class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {

			for (int i = 0; i < nums.size(); ++i) {
				for (int v = i; v < nums.size(); ++v) {
					if (nums[i] + nums[v] == target && i != v) return {i,v};
				}
			}

		}
};
