#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

		unordered_map<int, int> mp;
		for (int i = 0; i < nums.size(); i++) {
			mp[nums[i]]++;
		}

		unordered_map<int, int> smaller_count;

		int count = 0;
		for (int i = 0; i <= 100; i++) {
			if (mp.count(i)) {
				smaller_count[i] = count;
				count += mp[i];
			}
		}

		vector<int> ans;

		for (int x : nums) {
			ans.push_back(smaller_count[x]);
		}

		return ans;
	}
};
