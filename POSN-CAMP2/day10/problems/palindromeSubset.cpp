#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long

int cnt = 0;

void subsets(string& s, int n, int index, string& cur) {

	if (index == n) return;

	cur.push_back(s[index]);
	// do stuff
	
	string rev = cur;
	reverse(rev.begin(), rev.end());
	if (cur == rev) cnt++;
	
	subsets(s, n, index + 1, cur);

	cur.pop_back();
	if (cur.empty()) {
		subsets(s, n, index + 1, cur);
	}

}

signed main() {

	string s;
	cin >> s;

	string cur = "";

	subsets(s, s.size(), 0, cur);

	cout << cnt;

	return 0;

}
