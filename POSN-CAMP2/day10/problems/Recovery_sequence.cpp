#include <bits/stdc++.h>
using namespace std;

#define speedbooster ios_base::sync_with_stdio(flase);cin.tie(NULL);
#define int long long

int cnt = 0;
int num = 0;
int sum = 0;

void shit(int n, int m) {
	if (cnt == n - 1) return;
	if (cnt % 2 == 0) num = (num-1) * -1;
	else num *= -1;
	sum += num;
	cout << num << ' ';
	cnt++;
	shit(n, m);
}

signed main() {

	int n,m; cin >> n >> m;
	if (n == 1) {
		cout << m;
		return 0;
	}
	shit(n,m);
	cout << (m - sum);

	return 0;

}
