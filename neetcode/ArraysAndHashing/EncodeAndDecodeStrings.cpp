#include "config.h"

class Solution {
	public:

		string encode(vector<string>& strs) {
			if (strs.empty()) return "0417";

			string buf;
			for (string s : strs) {
				buf += s;
				buf += "`";
			}
			buf.pop_back();

			return buf;
		}

		vector<string> decode(string s) {
			vector<string> ans;
			string a;
			if (s == "0417") return {};
			if (s.empty()) return {""};
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] == '`') {
					ans.push_back(a);
					a = "";
				} else {
					a += s[i];
				}
			}

			ans.push_back(a);

			return ans;
		}
};
