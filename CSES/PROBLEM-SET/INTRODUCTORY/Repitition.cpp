#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long

signed main() {
	speed

	string s; cin >> s;
	int n = 1;
	int mx = 0;

	char last = s[0];
	
	for (signed i  = 1; i < s.size(); ++i) {
		if (s[i] == last) n++;
		else {
			mx = max(mx,n);
			n = 1;
		}
		last = s[i];
	}

	// DONT FORGET TO UPDATE AFTER LOOP
	mx = max(mx,n);

	cout << mx;

	return 0;
}
