#include "config.h"

class Solution {
	public:
		int trap(vector<int>& height) {
			vector<int> maxL(height.size(),0);
			int mxl = height[0];

			vector<int> maxR(height.size(),0);
			int mxr = 0;

			for (int i = 1; i < height.size(); ++i) {
				maxL[i] = mxl;
				mxl = max(mxl, height[i]);
			}

			for (int i = height.size() - 1; i >= 0; --i) {
				maxR[i] = mxr;
				mxr = max(mxr, height[i]);
			}

			// num of water = min(r,l) - height[i]
			
			int ans = 0;

			for (int i = 1; i < height.size(); ++i) {
				int n = min(maxL[i],maxR[i]) - height[i];
				if (n > 0) ans += n;
			}

			return ans;
		}
};
