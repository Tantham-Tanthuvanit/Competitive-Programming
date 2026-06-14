#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define int long long

// generate subset of apple and then calculate the difference between weight wiht the rest, take the min

void subsets(int i, vector<int>& arr, vector<int>& current, int sumOfArr, int& mn) {
	if (i == arr.size()) {
		// process subset
		// calculate the difference
		
		int sm = 0;
		for (int x : current) sm += x;
		int remSum = sumOfArr - sm;
		mn = min(mn, abs(remSum - sm));

		return;
	}

	// skip arr[i]
	subsets(i + 1, arr, current, sumOfArr, mn);

	// take arr[i]
	current.push_back(arr[i]);
	subsets(i + 1, arr, current, sumOfArr, mn);
	current.pop_back();
}

signed main() {
	int n; cin >> n;
	vector<int> apls;
	int sumOfArr = 0;
	while (n--) {
		int x; cin >> x;
		apls.push_back(x);
		sumOfArr += x;
	}
	vector<int> curr;
	int mn = INT_MAX;

	subsets(0,apls,curr,sumOfArr,mn);

	cout << mn;

	return 0;
}
