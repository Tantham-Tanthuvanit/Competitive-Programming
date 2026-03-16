#include <vector>

class Solution {
public:
	int sum = 0;
	
	void dfs(std::vector<int>& nums, int index, int currentXOR) {
		if (index == nums.size()) {
			sum += currentXOR;
			return;
		}

		// include nums [ index ]
		dfs(nums, index + 1, currentXOR ^ nums[index]);

		// exclide nums [ index ]
		dfs(nums, index +  1, currentXOR);

	}

	int subsetXORSum(std::vector<int>& nums) {
		dfs(nums, 0, 0);
		return sum;
	}
};
