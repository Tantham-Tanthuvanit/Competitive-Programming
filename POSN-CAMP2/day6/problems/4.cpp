#include <bits/stdc++.h>

using namespace std;

vector<int> comb;

int cnt = 0;
int n = 0,h = 0;

long long fac(int n) {
	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= i;
	}
	return ans;
}

void combination(int n, int r) {
	long long facN = fac(n);
	long long facR = fac(r);
	long long facNR = fac(n-r);
	
	cout << facN / (facNR*facR);
}

int main() {
	
	cin >> n >> h;
	
	combination(n,h);
	
	return 0;
}
