#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long

const int MOD = 1e9+7;

int modpow(int base, int exp) {
	int res = 1;
	while (exp > 0) {
		if (exp % 2) res = (res * base) % MOD;
		base = (base*base)%MOD;
		exp /= 2;
	}
	return res;
}

signed main() {
	speed

	int n; cin >> n;

	cout << modpow(2,n);
	
	return 0;
}
