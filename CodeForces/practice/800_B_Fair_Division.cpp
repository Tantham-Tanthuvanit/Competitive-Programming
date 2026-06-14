#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main() {
	int t; cin >> t;

	while (t--) {
		int n; cin >> n;

		vector<int> candies(n);
		int total = 0;

		for (int i = 0; i < n; ++i) {
			cin >> candies[i];
			total += candies[i];
		}

		// check if total weight if odd if it is then its impossible to get an even split
		if (total % 2 != 0) {
			cout << "NO" << endl;
			continue;
		}

		// our target of how much candies is needed
		int target = total / 2;

		// dp[w] is true if we can form exactly weight w with subset of candies
		vector<bool> dp(target + 1, false);
		dp[0] = true;

		for (int i = 0; i < n; ++i) {
			// iterate backwords to avoid reusing candies
			for (int w = target; w >= candies[i]; w--) {
				// check if target is reachable
				// or we can reach dp[w-candies[i]];
				dp[w] = dp[w] || dp[w - candies[i]];
			}
		}

		cout << (dp[target] ? "YES" : "NO") << endl;
	}

	return 0;
}
