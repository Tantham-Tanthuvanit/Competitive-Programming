#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
	speed

	int n; cin >> n;

	int c1 = 0,c2 = 0,c3 = 0,c4 = 0;


	while (n--) {
		int x; cin >> x;
		if (x == 1) c1++;
		else if (x == 2) c2++;
		else if (x == 3) c3++;
		else c4++;
	}

	int taxis = c4;

	taxis += c3;
	c1 = max(0,c1-c3);

	taxis += c2 / 2;
	
	if (c2 % 2) { 
		taxis++;
		c1 = max(0,c1-2);
	}

	taxis += (c1 + 3) / 4;

	cout << taxis;

	return 0;
}
