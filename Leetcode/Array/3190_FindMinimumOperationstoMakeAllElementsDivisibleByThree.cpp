#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
            sum += min(nums[i]%3, 3 - nums[i]%3);

        return sum;
    }
};