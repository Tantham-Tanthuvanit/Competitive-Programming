// get largest and second largest avaliable number at the moment and fill in the rest
#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long

signed main() {
	speed

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;

		int l = 1,r = 3*n;

		for (int i = 0; i < n; ++i) {
			cout << l << ' ' << r-1 << ' ' << r << ' ';
			l++;
			r -= 2;
		}
		cout << endl;
	}
	
	return 0;
}
