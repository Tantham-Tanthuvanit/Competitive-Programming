#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	int n, q, cmd, t, x;

	cin >> n >> q;

	vector<queue<int>> qq(n);

	string ans = "";

	while (q--) {

		cin >> cmd >> t;
		if (cmd == 0) {
			cin >> x;
			qq[t].push(x);
		}
		if (cmd == 1 && !qq[t].empty()) {
			ans += to_string(qq[t].front()) + '\n';
		}
		if (cmd == 2 && !qq[t].empty()) {
			qq[t].pop();
		}

	}

	cout << ans;

	return 0;
		
}
