#include <bits/stdc++.h>

using namespace std;

int dp[2][1001];

int BottomUp(int n, int k) {
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = 1;
	}
	
	for (int i = 0; i <= k; ++i) {
		dp[i][i] = 1;
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= k && j <= i; ++j) {
			dp[i][j] = dp[i-1[j] + dp[i-1]
[j-1];		}
	}
}

int main() {
	
	return 0;
	
}
