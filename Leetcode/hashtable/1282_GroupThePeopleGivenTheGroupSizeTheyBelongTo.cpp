#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		unordered_map<int, vector<int>> mp;

		for (int i = 0; i < groupSizes.size(); i++) {
			mp[groupSizes[i]].push_back(i);
		}

		vector<vector<int>> ans;

		for (auto& it : mp) {
			int size = it.first;
			auto& people = it.second;

			for (int i = 0; i < people.size(); i += size) {
				vector<int> group;
				for (int j = 0; j < size; j++) {
					group.push_back(people[i+j]);
				}
				ans.push_back(group);
			}
		}

		return ans;
	}
};
