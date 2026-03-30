#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

#define GUMP_HUA_KUY ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<int,int>

int main() {

	GUMP_HUA_KUY

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int n; cin >> n;

	while (n--) {
		int start,end; cin >> start >> end;
		pq.push({end,start});
	}
	
	int lastend = 0;
	int cnt = 0;

	while (!pq.empty()) {
		pii top = pq.top(); pq.pop();
		int end = top.first;
		int start = top.second;

		if (start >= lastend) {
			cnt++;
			lastend = end;
		}
	}

	cout << cnt;
	return 0;	
}
