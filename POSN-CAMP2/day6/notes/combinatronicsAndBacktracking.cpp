#include <algorithm>
#include <iostream>
#include <linux/limits.h>
#include <ostream>
#include <utility>
#include <vector>

using namespace std;

void permutate(vector<int> a, int l, int r) {
	if (l == r) {
		bool ok = false;
		for (int i = 0; i < r; i++)
			if ((a[i] == 1 && a[i+1] == 2) || (a[i] == 2 && a[i+1] == 1)) {
				ok = true;
				break;
            }

		if (ok) {
			for (int i = 0; i <= r; i++) {
				cout << a[i] << ' ';
			}
			cout << endl;

		}
		return;
	}

	for (int i = l; i <= r; i++) {
		swap(a[l], a[i]); // choose
		permutate(a, l+1, r);
		swap(a[l], a[i]); // backtrack
	}
}

int n = 10;
int k = 9;
/*
vector<int> comb = {1,2,3,4,5,6,7,8,9,10};

void combitations(int start, int depth) {
	if (depth == k) {
		for (int i = 0; i < k; i++) {
			cout << comb[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = start; i <= n; i++) {
		comb[depth] = i;
		combitations(i+1, depth+1);
	}
}
*/
vector<int> comb(5,0);

void generateBinaryCode(int k) {
	if (k == comb.size()) {
		for (int i = 0; i < comb.size(); i++)
			cout << comb[i];
		cout << endl;
		return;
	}

	comb[k] = 0;
	generateBinaryCode(k+1);

	comb[k] = 1;
	generateBinaryCode(k+1);
}

vector<int> a = {25,10,9,2};
vector<int> b = a;

void sumSub(int k) {
	if (k == a.size()) {
		int sum = 0;
		for (int i = 0; i < k; i++)
			sum += a[i];
		if (sum == 36) {
			for (int i = 0; i < k; i++) {
				if (a[i] != 0) cout << a[i] << ' ';
			}
			cout << endl;
			sum++;
		}
		return;
	}

	a[k] = 0;
	sumSub(k+1);
	a[k] = b[k];
	sumSub(k + 1);
}

void sumSubBacktrack(int k) {
	if (k == a.size()) {
		int sum = 0;
		for (int i = 0; i < k; i++)
			sum += a[i];
		if (sum == 36) {
			for (int i = 0; i < k; i++) {
				if (a[i] != 0) cout << a[i] << ' ';
			}
			cout << endl;
			sum++;
		}
		return;
	}

	a[k] = 0;
	sumSubBacktrack(k+1);
	a[k] = b[k];
	sumSubBacktrack(k + 1);
}


int main() {

	// combitations(1, 0);

	// generateBinaryCode(0);

	sumSub(0);

	return 0;
}
