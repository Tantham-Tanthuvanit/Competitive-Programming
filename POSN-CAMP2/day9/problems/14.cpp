#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define ULTRA ios_base::sync_with_stdio(false);cin.tie(NULL);

/*
 * 1. equal number of even and odd numbers inside the number
 * 2. divisible by K
*/

int cnt = 0;

void solve(int a, int b, int k) {
	if (a == b) return;
	
	int even = 0;
	int odd = 0;

	for (char c : to_string(a)) {
		if (int(c - '0')%2 == 0) even++;
		else odd++;
	}

	if (even == odd && a % k == 0) cnt++;

	solve(a+1, b, k);

}

int main() {

	ULTRA

	int a,b,k; cin >> a >> b >> k;
	solve(a, b, k);
	
	cout << cnt;

	return 0;

}
