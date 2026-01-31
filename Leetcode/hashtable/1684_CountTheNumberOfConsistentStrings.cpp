#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	int countConsistentStrings(string allowed, vector<string>& words) {
		unordered_map<char, bool> mp;
		bool skip= false;
		int count = 0;

		for (char ch : allowed) {
			mp[ch] = true;
		}

		for (int i = 0; i < words.size(); i++) {
			for (char ch : words[i]) {
				if (!mp[ch]) { skip = true; break;}
			}
			if (skip) {
				skip = false;
				continue;
			}
			else count++;
		}

		return count;
	}
};
