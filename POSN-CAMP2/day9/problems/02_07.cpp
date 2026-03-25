#include <bits/stdc++.h>
#include <type_traits>
#include <vector>
using namespace std;

struct ans {
	int val;
	pair<int,int> tl,tr,bl,br;
};

ans matrix(vector<vector<int>>& a) {

	int m = a.size(), n=a[0].size();
	ans res = { INT_MIN, {0,0},{0,0},{0,0}};
	for (int l = 0; l < m; ++l) {
		vector<int> o(n,0);
		for (int r = l; r < m; ++r) {
			for (int i = 0; i < n; ++i) {
				o[i] += a[i][r];
			}
			int cur = 0, s = 0;
			for (int i = 0; i < n; i++) {
				if (cur <= 0) {
					cur = o[i];
					s = i;
				}
				else cur += o[i];
				if (cur > res.val) {
					res.val = cur;
					res.tl = {s,l};
					res.tr = {s,r};
					res.bl = {i,l};
					res.br = {i,r};
				}

			}
		}
	}
	return res;
}

int main() {
	int a;
	cin >> a;
	vector<vector<int>> l(a,vector<int>(a));
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < a; ++j) {
			cin >> l[i][j];
		}
	}
	ans dat = matrix(l);
	cout << dat.val << " ("<<dat.tl.first<<", "<<dat.tl.second<<") ("<<dat.tr.first<<", "<<dat.tr.second<<") ("<<dat.bl.first<<", "<<dat.bl.second<<") ("<<dat.br.first<<", "<<dat.br.second<<")";
}
