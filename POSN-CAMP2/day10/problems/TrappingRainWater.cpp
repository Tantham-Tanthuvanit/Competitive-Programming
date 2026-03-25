#include <bits/stdc++.h>
using namespace std;

#define SPEEEEEEEEDDDD ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main() {
	SPEEEEEEEEDDDD

	int n; cin >> n;
cout << "n = " << n << "\n";

	if (n < 3) {
		cout << 0;
		return 0;
	}

	vector<int> walls(n);
	for (int i = 0; i < n; i++)
		cin >> walls[i];

	vector<int> left(n);
	vector<int> right(n);

	left[0] = walls[0];
	for (int i = 1; i < n; i++)
		left[i] = max(left[i-1],walls[i]);

	right[n-1] = walls[n-1];
	for (int i = n-2; i>= 0; i++)
		right[i] = max(right[i+1],walls[i]);

	int sum = 0;
	for (int i = 1; i < n - 1; i++)
		sum += min(left[i],right[i]) - walls[i];

	cout << sum;

	return 0;
}
