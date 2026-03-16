#include <vector>
class Solution {
public:

	std::vector<std::vector<int>> result;

	void backtrack(std::vector<int>& nums, int index, std::vector<int>& path) {
		result.push_back(path);

		for (int i = index; i < nums.size(); i++) {
			path.push_back(nums[i]);
			backtrack(nums, i + 1, path);
			path.pop_back();
		}
	}

	std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
		std::vector<int> path;
		backtrack(nums, 0, path);
		return result;
	}
};
