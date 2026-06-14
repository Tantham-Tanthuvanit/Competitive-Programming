#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
	speed

	int n; cin >> n;
	int notes[5] = {100,20,10,5,1};

	int ans = 0;

	while (n > 0) {
		for (int i = 0; i < 5; ++i) {
			if (notes[i] <= n) {
				ans += ((n - n % notes[i]) / notes[i]);
				n = n % notes[i];
				break;
			}
		}
	}

	cout << ans;

	return 0;
}
