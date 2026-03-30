#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
	speed;

	int m,n; cin >> m >> n;
	vector<vector<int>> a(m,vector<int>(n));
	vector<vector<int>> b(m,vector<int>(n));

	for (int i = 0; i < m; ++i)
		for (int v = 0; v < n; ++v)
			cin >> a[i][v];

	for (int i = 0; i < m; ++i)
		for (int v = 0; v < n; ++v)
			cin >> b[i][v];

	for (int i = 0; i < m; ++i) {
		for (int v = 0; v < n; ++v)
			cout << a[i][v] + b[i][v] << ' ';
		cout << endl;
	}

	return 0;
}
