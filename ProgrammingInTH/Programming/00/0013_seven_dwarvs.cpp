#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<vector<int>> res;
void solve(int start, vector<int>& comb, int k, vector<int>& nums, int sum) {
	if (comb.size() == k) {
		if (sum == 100) {
			res.push_back(comb);
		}
		return;
	}

	for (int i = start; i < nums.size(); ++i) {
		comb.push_back(nums[i]);
		solve(i+1, comb,k,nums, sum + nums[i]);
		comb.pop_back();
	}

	return;
}

int main() {
	speed

	vector<int> nums(9);
	for (int i = 0; i < 9; ++i) cin >> nums[i];

	vector<int> comb;
	solve(0,comb, 7, nums,0);

	for (auto& x : res) {
		for (auto i : x) {
			cout << i << endl;
		}
	}

	return 0;
}
