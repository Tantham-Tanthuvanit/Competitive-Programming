#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int numJewelsInStones(string jewels, string stones) {
		
		unordered_map<char, bool> mp;
		int count = 0;

		for (int i = 0; i < jewels.size(); i++) {
			mp[jewels[i]] = true;
		}

		for (char stone : stones) {
			if (mp[stone]) count++;
		}

		return count;
	}
};
