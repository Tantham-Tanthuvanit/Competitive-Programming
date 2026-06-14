#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> subsets;

// most basic form of subset
// kinda useless
void subset(int k) {
	if (k == n) {
		// process subset
	} else {
		subset(k+1);
		subsets.push_back(k);
		subset(k+1);
		subsets.pop_back();
	}
}

// array subsets
void subset2(int i, vector<int>& arr, vector<int>& current) {
	if (i == arr.size()) {
		// process subset
		return;
	}
	// skip arr[i]
	subset2(i+1,arr,current);

	// take arr[i]
	current.push_back(arr[i]);
	subset2(i+1,arr,current);
	current.pop_back();
}

int main() {

	return 0;
}
