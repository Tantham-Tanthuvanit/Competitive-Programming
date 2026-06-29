#include <bits/stdc++.h>
#include <ios>
using namespace std;

void fastIO() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	(void)freopen("input.txt","r",stdin);
	#endif
}

void solve() {
	int n; cin >> n;
	vector<int> prices(n+1,0);
	for (int i = 1; i <= n; ++i) {
		cin >> prices[i];
	}

	vector<int> table(n+1,0);
	for (int length = 1; length <= n; ++length) {
		for (int i = 1; i <= length; ++i) {
			int tmp = prices[i] + table[length-i];
			if (tmp > table[length])
				table[length] = tmp;
		}
	}

	cout << table[n] << endl;
}

int main() {
	fastIO();

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
