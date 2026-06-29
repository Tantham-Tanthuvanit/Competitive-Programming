#include <bits/stdc++.h>
using namespace std;

void fast_io() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	(void)freopen("input.txt","r",stdin);
	#endif
}

int rod_cutting(int length,vector<int>& price,vector<int>& mem) {
	if (length == 0) return 0;
	if (mem[length] != -1) return mem[length];
	int mx = INT_MIN;
	for (int i = 1; i <= length; ++i) {
		int tmp = price[i] + rod_cutting(length - i, price, mem);
		if (tmp > mx) mx = tmp;
	}
	mem[length] = mx;
	return mx;
}

void solve() {
	int n; cin >> n;
	vector<int> prices(n+1,0);
	vector<int> mem(n+1,-1);

	for (int i = 1; i <= n; ++i)
		cin >> prices[i];

	cout << rod_cutting(n,prices,mem);	
}

int main() {
	fast_io();

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
