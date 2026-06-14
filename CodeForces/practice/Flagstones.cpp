#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
	speed

	long long n,m,a;
	cin >> n >> m >> a;
	n = n/a + (n%a!=0); // ceil
	m = m/a + (m%a!=0);
	cout << n * m << endl;

	return 0;
}
