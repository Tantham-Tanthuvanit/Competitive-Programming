#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
	speed

	string s; cin >> s;
	vector<int> values(3,0);
	values[0] = 1;

	for (char c : s) {
		if (c == 'A') swap(values[0],values[1]);
		if (c == 'B') swap(values[1],values[2]);
		if (c == 'C') swap(values[0],values[2]);
	}

	for (int i = 0; i < 3; ++i) {
		if (values[i] == 1) {
			cout << i+1;
		}
	}

	return 0;
}
