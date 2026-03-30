#include <bits/stdc++.h>
using namespace std;

#define KUY_GUMP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long

vector<vector<int>> mp;
vector<vector<int>> lookup;
int cnt = 0;

int V(int m,int n) {
    cnt++;

    if (lookup[m][n] != -1) return lookup[m][n];
    if (m == 0 || n == 0) return -1;

    int left = V(m-1,n-1);
	int up   = V(m-1,n);

	if (m == 1)
		return lookup[m][n] = mp[m][n];
	if (left == -1 && up == -1)
		return lookup[m][n] = -1;

	if (left == -1)
		return lookup[m][n] = mp[m][n] + up;

	if (up == -1)
        return lookup[m][n] = mp[m][n] + left;

    return lookup[m][n] = mp[m][n] + max(left, up);
}

signed main() {
    int n,m; cin >> n >> m;

    mp.resize(n+1, vector<int>(m+1,0));
    lookup.resize(n+1, vector<int>(m+1,-1));

    for (int i = 1; i <= n; ++i)
        for (int v = 1; v <= m;++v)
            cin >> mp[i][v];

    cout << V(n,m) << endl;
    cout << cnt-1 << endl;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << lookup[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
