#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int numIdenticalPairs(vector<int>& nums) {
		unordered_map<int,int> count;
		int good_pairs = 0;

		for (int i = 0; i < nums.size(); i++) {
			good_pairs += count[nums[i]];
			count[nums[i]]++;

		return good_pairs;
		}
	}
};

int main() {
	return 0;
}
