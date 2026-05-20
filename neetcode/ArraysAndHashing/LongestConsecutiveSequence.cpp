#include "config.h"

class Solution {
	public:
		int longestConsecutive(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			if (nums.empty()) return 0;
			int n = 1;
			int maxN = 1;
			for (int i = 1; i < nums.size(); ++i) {
				if (nums[i] == nums[i-1]) continue;
				if (nums[i-1] + 1 == nums[i]) {
					n++;
					maxN = max(maxN,n);
				}	
				else n = 1;
			}
			
			return maxN;
		}
};
