#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> counter;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (counter.count(nums[i]) > 0) ans.push_back(nums[i]);
            else counter[nums[i]] = 1;
        }

        return ans;
    }
};