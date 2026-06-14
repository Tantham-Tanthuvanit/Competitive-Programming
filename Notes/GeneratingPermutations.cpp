#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int n = 10;

void recPerm(vector<int>& permutation, vector<vector<int>>& permutations, vector<bool>& chosen) {
	if (permutation.size() == n) {
		// process permutation
		permutations.push_back(permutation);
	} else {
		for (int i = 0; i < n; ++i) {
			// permutaiton generating code
			if (chosen[i]) continue;
			chosen[i] = true;
			permutation.push_back(i);
			recPerm(permutation, permutations, chosen);
			chosen[i] = false;
			permutation.pop_back();
		}
	}
}

void stdPerm() {
	vector<int> permutation;
	vector<vector<int>> permutations;
	for (int i = 0; i < n; ++i) {
		permutation.push_back(i);
	}
	do {
		permutations.push_back(permutation);
	} while(next_permutation(permutation.begin(), permutation.end()));
}

int main() {
	return 0;
}
