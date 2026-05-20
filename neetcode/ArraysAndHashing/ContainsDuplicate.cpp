#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

class Solution {
	public:
		bool hasDuplicate(vector<int>& nums) {
			set<int> s(nums.begin(),nums.end());
			return s.size() == nums.size() ? false : true;
		}
};
