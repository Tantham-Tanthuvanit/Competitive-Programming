#include <bits/stdc++.h>

using namespace std;

vector<string> ansVec;

void permutate(vector<char> a, int l, int r) {
	if (l == r) {
		string ans = "";
		for (int i = 0; i <= r; i++) {
			ans += a[i];
		}
		ansVec.push_back(ans);
		return;
	}
	
	for (int i =l; i <= r; i++) {
		swap(a[l], a[i]); // choose
		permutate(a, l+1, r);
		swap(a[i], a[l]); // backtrack
	}
}

int main() {
	
	int n; cin >> n;
	vector<char> v;
	while (n--) {
		char c; cin >> c;
		v.push_back(c);
	} 
	
	permutate(v, 0, v.size()-1);
	
	sort(ansVec.begin(), ansVec.end());
	
	for (const string& i : ansVec) {
		cout << i << endl;
	}
	
	return 0;
}
