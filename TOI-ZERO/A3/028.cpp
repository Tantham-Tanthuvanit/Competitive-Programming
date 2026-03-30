#include <bits/stdc++.h>
#include <string_view>
#include <vector>
using namespace std;
#define GUMP_HUA_KUY ios_base::sync_with_stdio(false);cin.tie(NULL)

int main() {
	int n,m; cin >> n >> m;
	vector<vector<int>> mp(n,vector<int>(m,0));

	int bombN; cin >> bombN;

	while (bombN--) {
		int x,y; cin >> y >> x;
		mp[y][x] = -1;
	}

	for (int i = 0; i < n; ++i) {
		for (int v = 0; v < m; ++v) {
			if (mp[i][v] == -1) continue;
			if (v - 1 >= 0 && mp[i][v-1] == -1) mp[i][v]++;
			if (v + 1 < m && mp[i][v+1] == -1) mp[i][v]++;
			if (i - 1 >= 0 && mp[i-1][v] == -1) mp[i][v]++;
			if (i + 1 < n && mp[i+1][v] == -1) mp[i][v]++;

			if (v - 1 >= 0 && i - 1 >= 0 && mp[i-1][v-1] == -1) mp[i][v]++;
			if (v + 1 < m && i - 1 >= 0 && mp[i-1][v+1] == -1) mp[i][v]++;
			if (v - 1 >= 0 && i + 1 < n && mp[i+1][v-1] == -1) mp[i][v]++;
			if (v + 1 < m && i + 1 < n && mp[i+1][v+1] == -1) mp[i][v]++;
		}
	}

	
	for (int i = 0; i < n; ++i) {
		for (int v = 0; v < m; ++v) {
			cout << (mp[i][v] == -1 ? string("x") : to_string(mp[i][v])) << ' ';
		}
		cout << endl;
	}

	return 0;

}
