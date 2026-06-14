#include "config.h"

class Solution {
	public:
		vector<int> dailyTemperatures(vector<int>& temperatures) {

			stack<int> stk;
			vector<int> ans(temperatures.size(),0);

			for (int i = temperatures.size()-1; i >= 0; --i) stk.push(temperatures[i]);

			for (int i = 0; i < temperatures.size(); ++i) {
				int cur = stk.top(); stk.pop();
				stack<int> newstk = stk;
				int cnt = 1;
				while (!newstk.empty()) {
					if (newstk.top() > cur) {
						ans[i] = cnt;
						break;
					}
					cnt++;
					newstk.pop();
				}
				if (!newstk.empty()) {
					ans[i] = cnt;
				}
			}

			return ans;

		}
};
