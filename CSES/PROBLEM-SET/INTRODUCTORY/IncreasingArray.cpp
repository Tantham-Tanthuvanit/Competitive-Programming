#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long

signed main() {

	speed
	
	int n; cin >> n;
	int last; cin >> last;
	int moves = 0;

	for (int i = 1; i < n; ++i) {
		int x; cin >> x;
		if (x < last) {
			moves += last-x;
			last = last;
		} else {
			last = x;
		}
	}

	cout << moves;

	return 0;

}
