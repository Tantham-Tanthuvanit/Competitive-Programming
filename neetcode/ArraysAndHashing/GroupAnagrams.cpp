#include "config.h"

class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			unordered_map<string,vector<string>> exists;

			for (int i = 0; i < strs.size(); ++i) {
				string str = strs[i];
				sort(str.begin(), str.end());
				exists[str].push_back(strs[i]);
			}

			vector<vector<string>> ans;

			for (auto [key,value] : exists) {
				ans.push_back(value);
			}

			return ans;

		}
};

