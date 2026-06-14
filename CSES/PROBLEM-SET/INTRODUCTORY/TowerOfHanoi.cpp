#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);

void th(int n, int s, int e, int a) {
	if (n == 1) {
		cout << s << ' ' << e << endl;
		return;
	}
	th(n-1,s,a,e);
	cout << s << ' ' << e << endl;
	th(n-1,a,e,s);
	return;
}

int main() {
	speed

	int n; cin >> n;

	// min n of moves is 2 ^ n - 1
	cout << pow(2.0f, n) - 1 << endl;
	th(n,1,3,2);

	return 0;
}
