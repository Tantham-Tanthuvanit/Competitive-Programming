#include "config.h"

class Solution {
	public:
		int maxArea(vector<int>& heights) {

			int l = 0;
			int r = heights.size() - 1;

			long long mx = 0;

			while (l < r) {
				mx = max((long long)min(heights[l],heights[r]) * (r-l),(long long)mx);
				if (heights[l] <= heights[r]) {
					l++;
				}
				else {
					r--;
				}
			}

			return mx;

		}
};
