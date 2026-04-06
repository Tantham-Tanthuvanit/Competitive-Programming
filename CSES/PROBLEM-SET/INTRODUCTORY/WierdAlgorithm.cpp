#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long

void algo(int& n) {

	cout << n << ' ';

	if (n == 1) return;

	if (n % 2 == 0) n /= 2;
	else n = (n * 3) + 1;

	algo(n);

	return;
}

signed main() {
	speed	

	int n; cin >> n;
	algo(n);

	return 0;
}
