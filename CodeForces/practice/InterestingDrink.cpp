#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long

signed main() {
	speed

	int n; cin >> n;	
	vector<int> shops;
	while (n--) {
		int x; cin >> x;
		shops.push_back(x);
	}

	sort(shops.begin(), shops.end());
	
	int q; cin >> q;

	for (int i = 0; i < q; ++i) {
		int m; cin >> m;
		int ans = upper_bound(shops.begin(), shops.end(), m) - shops.begin();
		cout << ans << endl;
	}

	return 0;
}
