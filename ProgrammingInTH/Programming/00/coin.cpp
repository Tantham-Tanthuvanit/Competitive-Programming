#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
	int n; cin >> n;

	vector<int> counts(4);

	while (n > 0) {
		if (n >= 10) { counts[0]++; n-=10; continue; }
		if (n >= 5) { counts[1]++; n-=5; continue; }
		if (n >= 2) { counts[2]++; n-=2; continue; }
		if (n >= 1) { counts[3]++; n-=1; continue; }
	}

	cout << "10 = " << counts[0] << endl;
	cout << "5 = " << counts[1] << endl;
	cout << "2 = " << counts[2] << endl;
	cout << "1 = " << counts[3] << endl;
}
