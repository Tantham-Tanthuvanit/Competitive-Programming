#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long

signed main() {
	speed
	int t; cin >> t;
	while (t--) {
		vector<int> v(7);
		for (int i = 0; i < 7; ++i)
			cin >> v[i];

		sort(v.begin(),v.end());

		int sum = 0;
		for (int i = 0; i < 6; ++i)
			sum += (v[i]*-1);
		sum += v[6];
		cout << sum << endl;
	}
	return 0;
}
