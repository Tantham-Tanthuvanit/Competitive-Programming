#include "config.h"

class Solution {
	public:
		vector<int> twoSum(vector<int>& numbers, int target) {
			int l = 0;
			int r = numbers.size() - 1;

			for (int i = l; i < r; ++i) {
				for (int v = r; v > l; --v) {

					if (numbers[i] + numbers[v] == target) return {i+1,v+1};

				}
			}

		}
};
