#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,q,op,t,x; cin >> n >> q;
	vector<stack<int>> v(n);

	while (q--) {
		cin >> op;
		if (op == 0) {
			cin >> t >> x;
			v[t].emplace(x);
		}
		if (op == 1) {
			cin >> t;
			if (!v[t].empty()) cout << v[t].top() << '\n';
		}
		if (op == 2) {
			cin >> t;
			if (!v[t].empty()) v[t].pop();
		}
	}
	return 0;
}
