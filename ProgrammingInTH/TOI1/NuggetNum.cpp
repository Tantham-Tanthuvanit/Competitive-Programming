#include <bits/stdc++.h>

using namespace std;

#define FUCK ios_base::sync_with_stdio(0);cin.tie(NULL);

int main() {
	
	FUCK
	
	int n; cin >> n;
	int nuggetNums[3] = {6,9,20};
	vector<int> ans;
	
	for (int i = 0; i < n; i+=6) {
		for (int v = 0; v < n; v+=9) {
			for (int k = 0; k < n; k+=20) {
				if (n % i + v + k == 0) {
					ans.push_back(n);
				}
			}
		}
		n--;
	}
	
	sort(ans.begin(), ans.end());
	for (int i : ans) {
		cout << i << endl;
	}
	
	return 0;
}
