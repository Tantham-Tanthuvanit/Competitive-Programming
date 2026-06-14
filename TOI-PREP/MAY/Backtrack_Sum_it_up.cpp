#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int ans = 0;
void bt(int i, int curSum, int t, vector<int>& nums) {

	if (i == nums.size()) {
		if (curSum == t) {
			ans++;
			return;
		}
	}

	if (i >= nums.size() || curSum > t) return;

	// choose current element
	bt(i + 1, curSum + nums[i], t, nums);
	// skip current element
	bt(i + 1, curSum, t, nums);

}

int main() {
	speed
	
	int t,n; cin >> t >> n;
	vector<int> nums(n);
	
	for (int i = 0; i < n; ++i) cin >> nums[i];

	bt(0,0,t,nums);

	(ans == 0) ? cout << -1 : cout << ans;
	
	return 0;
}
