#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
	speed

	set<int> ans;

	for (int i = 0; i < 10; ++i) {
		int x; cin >> x;
		ans.insert(x%42);
	}	

	cout << ans.size();

	return 0;
}
