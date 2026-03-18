#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> ans;

	while (true) {
		int c;
		cin >> c;
		if (c == 0) break;
		ans.push_back(c);
	}

	sort(ans.begin(), ans.end());

	for (int i : ans) cout << i << ' ';

	return 0;
	
}
