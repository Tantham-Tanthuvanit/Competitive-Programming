#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long

signed main() {
	speed

	int n; cin >> n;
	int sum = n * (n + 1)/2;

	int otherSum = 0;

	for (int i = 0; i < n-1; ++i) {
		int x; cin >> x;
		otherSum += x;
	}

	cout << sum - otherSum;
	return 0;
}
