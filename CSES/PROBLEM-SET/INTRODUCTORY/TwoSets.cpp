#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long

signed main() {
	speed

	// if sum of all numbers is even then 2 balanced sets is possible
	// with the sole exception of 2
	
	int n; cin >> n;
	int sumON = n*(n+1)/2;

	if (sumON % 2 == 1) {
		cout << "NO";
		return 0;
	} else {
		// if even then start the first set by the highest num and second set with lowest num
		cout << "YES" << endl;
		vector<int> a,b;
		if (n % 4 == 0) {
			for (int i = 1; i <= n; i += 4) {
				a.push_back(i);
				a.push_back(i + 3);
				b.push_back(i + 1);
				b.push_back(i + 2);
			}
		} else {
			a.push_back(1);
			a.push_back(2);
			b.push_back(3);

			for (int i = 4; i <= n; i += 4) {
				a.push_back(i);
				a.push_back(i + 3);
				b.push_back(i + 1);
				b.push_back(i + 2);
			}
		}

		cout << a.size() << endl;
		for (int x : a) cout << x << ' ';
		cout << endl << b.size() << endl;
		for (int j : b) cout << j << ' ';
	}

	return 0;
}
