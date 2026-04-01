#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
	speed

	int nums[3] = {0};
	int a,b,c; cin >> a >> b >> c;
	string s; cin >> s;
	nums[0] = min(a,min(b,c));
	nums[2] = max(a,max(b,c));
	nums[1] = (a + b + c) - nums[0] - nums[2];

	for (char c : s) {
		cout << nums[c-'A'] << ' ';
	}

	return 0;
}
