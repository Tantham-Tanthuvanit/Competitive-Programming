#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);

void gen(string& s, int i, int& ans, int& ones) {
	int n = s.size();

	if (i == n) {
		int sumOfValues = 0;
		for (char c : s) {
			sumOfValues += (c - '0');
		}
		if (sumOfValues == ones) ans++;
		return;
	}

	s[i] = '0';
	gen(s,i+1,ans,ones);

	s[i] = '1';
	gen(s,i+1,ans,ones);
}

int main() {
	speed

	int n,ones; cin >> n >> ones;
	int ans = 0;

	string s(n,'0');

	gen(s,0,ans,ones);

	cout << ans;

	return 0;
}
