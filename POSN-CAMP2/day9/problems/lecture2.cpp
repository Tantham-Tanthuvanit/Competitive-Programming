#include <bits/stdc++.h>
using namespace std;

int lookup[1005][1005];
int cnt = 0;

int C(int n, int k) {
	cnt++;
	// check lookup table
	if (lookup[n][k] != -1) return lookup[n][k];
	if (n == k || k == 0) return 1;

	// conditional function call (check before calling recursive)
	if (lookup[n-1][k] == -1) lookup[n-1][k] = C(n-1,k);
	if (lookup[n-1][k-1] == -1) lookup[n-1][k-1] = C(n-1,k-1);
	// set lookup table
	lookup[n][k] = lookup[n-1][k] + lookup[n-1][k-1];
	return lookup[n][k];
}

int main() {
	memset(lookup, -1, sizeof(lookup));
	cout << C(20,4) << endl;
	cout << cnt;
	return 0;
}
