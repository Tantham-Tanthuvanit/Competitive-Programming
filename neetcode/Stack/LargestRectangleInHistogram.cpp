#include "config.h"

class Solution {
	public:
		int largestRectangleArea(vector<int>& heights) {
			stack<int> s;
			int mx = INT_MIN;
			int currentArea = 0;

			for (int i = 0; i < heights.size(); ++i) {
				while (!s.empty() && heights[s.top()] > heights[i]) {
					int top = s.top(); s.pop();
					if (s.empty()) {
						currentArea = heights[top] * i;
					} else {
						currentArea = heights[top] * (i - (s.top()+1));
					}
					mx = max(mx, currentArea);
				}
				s.push(i);
			}
			while (!s.empty()) {
				int top = s.top(); s.pop();
				if (s.empty()) {
					currentArea = heights[top] * heights.size();
				} else {
					currentArea = heights[top] * (heights.size() - (s.top() + 1));
				}
				mx = max(mx, currentArea);
			}
			return mx;
		}
};
