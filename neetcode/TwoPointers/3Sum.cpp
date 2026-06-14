#include "config.h"
using namespace std;

class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {

			sort(nums.begin(), nums.end());

			vector<vector<int>> ans;
			
			for (int i = 0; i < nums.size(); ++i) {
           if (i > 0 && nums[i] == nums[i-1]) continue;
		   if (nums[i] > 0) break;
				int numi = nums[i];
				int l = i+1;
				int r = nums.size()-1;
				while (l < r) {
					int sum = numi + nums[l] + nums[r];
					if (sum == 0) {
						ans.push_back({numi, nums[l], nums[r]});
						l++;
						r--;
						while (l < r && nums[l] == nums[l-1]) l++;
						while (l < r && nums[r] == nums[r+1]) r++;
					}
					else if (sum < 0) l++;
					else r--;
				}
			}

			return ans;

		}
};
