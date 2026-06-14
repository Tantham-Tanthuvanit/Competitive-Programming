#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
	speed
	
	int x; cin >> x;

	if (x < 1582) {
		if (x % 4 == 0) cout << "yes";
		else cout << "no";
		return 0;
	}
	if (x % 400 == 0) cout << "yes";
	else if (x % 100 == 0) cout << "no";
	else if (x % 4 == 0) cout << "yes";
	else cout << "no";

	return 0;
}
