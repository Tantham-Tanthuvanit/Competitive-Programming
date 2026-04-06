#include <bits/stdc++.h>
#include <ostream>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long

signed main() {
	speed

	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		if (x == -67) {
			cout << -67 << endl;
			continue;
		}
		if (x == 67) {
			cout << 67 << endl;
			continue;
		}
		cout << x + 1 << endl;
	}

	return 0;
}
