// bt 1
#include <bits/stdc++.h>

using namespace std;

#define V ios_base::sync_with_stdio(0);cin.tie(NULL);

set<vector<int>> check;

void getPerm(int& ans, int target, int k, vector<int>& arr, vector<int>& arrB) {
	if (k == arr.size()) {
		int sum = 0;
		vector<int> currentCom;
		for (int i = 0; i < k; i++) {
			sum += arr[i];
			if (arr[i] != 0) currentCom.push_back(arr[i]);
		}
		if (sum == target) {
			sort(currentCom.begin(), currentCom.end());
			check.insert(currentCom);
		}
		return;
	}
	
	arr[k] = 0;
	getPerm(ans, target, k+1, arr, arrB);
	arr[k] = arrB[k];
	getPerm(ans, target, k+1, arr, arrB);

}

int main() {
	
	V
	
	int target, n; cin >> target >> n;
	
	vector<int> arr;
	int ans = 0;
	
	while (n--) {
		int g; cin >> g;
		arr.push_back(g);
	}
	
	vector<int> arrB = arr;
	
	getPerm(ans, target, 0, arr, arrB);
	
	check.size() != 0 ? cout << check.size() : cout << -1;
	
}
