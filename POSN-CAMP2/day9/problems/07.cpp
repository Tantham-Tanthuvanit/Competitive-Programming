#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define speed_booster ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
	int n; cin >> n;

	vector<int> prices(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> prices[i];

	vector<int> dp(n+1,0);

	for (int i = 0; i <= n; ++i) {
		dp[i] = prices[i];

		for (int j = 0; j < i; ++j) {
			dp[i] = max(dp[i], prices[j] + dp[i-j]);
		}
	}

	cout << dp[n];

	return 0;
}
