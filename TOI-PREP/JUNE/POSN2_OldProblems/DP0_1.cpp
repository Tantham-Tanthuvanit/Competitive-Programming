#include <bits/stdc++.h>
#include <ios>
using namespace std;

typedef vector<vector<int>> vvi;

void fast_io() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	(void)freopen("input.txt","r",stdin);
	#endif
}

int solve(vvi& grid, int m, int n, vvi& mem) {
	if (m == 0 || n == 0) {
		return 0;
	}
	if (mem[m][n] != -1) return mem[m][n];

	mem[m][n] = grid[m][n] + max(solve(grid,m-1,n-1,mem),solve(grid,m-1,n,mem));
	return mem[m][n];
}

int main() {
	fast_io();

	int m,n; cin >> m >> n;
	vvi grid(m,vector<int>(n,0));
	vvi mem(m,vector<int>(n,-1));
	for (int i = 0; i < m; ++i) {
		for (int v = 0; v < n; ++v) {
			cin >> grid[i][v];
		}
	}

	cout << solve(grid, m - 1, n - 1, mem);

	return 0;
}
