#include <bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);

int dirx[4] = {1,-1,0,0};
int diry[4] = {0,0,1,-1};

void dfs(vector<vector<char>>& grid, pair<int,int> start, vector<vector<bool>>& visited) {

	int x,y;
	x = start.first;
	y = start.second;

	if (visited[x][y] || grid[x][y] == '#') return;
	visited[x][y] = true;

	for (int i = 0; i < 4; ++i) {
		if (x + dirx[i] < 0 || x + dirx[i] >= grid.size() || y + diry[i] < 0 || y + diry[i] >= grid[0].size()) continue;
		dfs(grid,{x + dirx[i],y + diry[i]},visited);
	}

	return;

}

int main() {
	speed

	int n,m;
	cin >> n >> m;

	vector<vector<char>> mp(n,vector<char>(m));
	vector<vector<bool>> visited(n,vector<bool>(m,false));

	for (int i = 0; i < n; ++i)
		for (int v = 0; v < m; ++v)
			cin >> mp[i][v];

	int ans = 0;

	for (int i = 0; i < n; ++i)
		for (int v = 0; v < m; ++v) {
			if (mp[i][v] == '.' && visited[i][v] == false) {
				dfs(mp,{i,v},visited);
				ans++;
			}
		}

	cout << ans;

	return 0;
}
