#include <bits/stdc++.h>

using namespace std;

#define ULTRA ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
	ULTRA

	priority_queue<int, vector<int>, greater<int>> pq;
	int mass, n; cin >> mass >> n;

	int a = n;
	while (n--) {
		int asteroid; cin >> asteroid;
		pq.push(asteroid);
	}

	for (int i = 0; i < a; ++i) {
		int cur = pq.top(); pq.pop();
		if (cur <= mass) {
			mass += cur;
		} else {
			cout << "false";
			return 0;
		}
	}

	cout << "true";

	return 0;
}
