#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void subsetGen(vector<int> subset, int k, int n) {
	if (k == n) {
		// subset has been completed
		for (int x : subset) cout << x << ' ';
		cout << endl;
	} else {
		subsetGen(subset, k+1, n);
		subset.push_back(k);
		subsetGen(subset, k+1, n);
		subset.pop_back();
	}
}

void permutations(vector<int> permutation, int n, unordered_map<int, bool> chosen) {
	if (permutation.size() == n) {
		// process permutation
		for (int x : permutation) cout << x << ' ';
		cout << endl;
	} else {
		for (int i = 0; i < n; ++i) {
			if (chosen[i]) continue;
			chosen[i] = true;
			permutation.push_back(i);
			permutations(permutation, n, chosen);
			chosen[i] = false;
			permutation.pop_back();
		}
	}
}

int main() {
	return 0;
}
