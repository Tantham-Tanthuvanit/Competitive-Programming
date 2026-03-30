#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
	int n; cin >> n;
	int m = INT_MAX;
	int mx = INT_MIN;

	while (n--) {
		int x; cin >> x;
		m = min(m,x);
		mx = max(mx,x);
	}

	cout << m << endl << mx;

	return 0;
}
