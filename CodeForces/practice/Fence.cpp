#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
	speed

	// remove fences that are k consecutively and make their sum as small as possible
	int n,k; cin >> n >> k;

	vector<int> fence(n);

	for (int i = 0; i < n; ++i)
		cin >> fence[i];

	int ans = 0;
	int sum = 0;
	for (int i = 0; i < k; ++i) sum += fence[i];
	int mn = sum;
	for (int i = k; i < n; ++i) {
		sum -= fence[i-k];
		sum += fence[i];
		if (sum < mn) {
			mn = sum;
			ans = i-k+1;
		}
	}

	cout << ans + 1;

	return 0;
}
