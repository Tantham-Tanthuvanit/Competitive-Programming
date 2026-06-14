#include <bits/stdc++.h>
using namespace std;

void perm(string& permutation, string& orig, vector<bool>& chosen, size_t n, vector<string>& res) {
	if (permutation.size() == n) {
		res.push_back(permutation);
		return;
	} else {
		for (int i = 0; i < n; ++i) {
			if (chosen[i]) continue;
			if (i > 0 && orig[i] == orig[i-1] && !chosen[i-1]) continue;
			chosen[i] = true;
			permutation.push_back(orig[i]);
			perm(permutation, orig, chosen, n, res);
			chosen[i] = false;
			permutation.pop_back();
		}
	}
}

int main() {
	string s; cin >> s;
	vector<bool> chosen(s.size(),false);
	string permutation = "";
	vector<string> res;

	sort(s.begin(),s.end());

	perm(permutation,s,chosen,s.size(),res);
	cout << res.size() << endl;
	for (const auto result : res) cout << result << endl;

	return 0;
}
