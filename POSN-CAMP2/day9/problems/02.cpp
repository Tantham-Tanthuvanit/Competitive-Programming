#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m; cin >> n >> m;

    vector<vector<int>> mp(n+1, vector<int>(m+1));
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> mp[i][j];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = mp[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
        }
    }

    cout << dp[n][m] << '\n';

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
