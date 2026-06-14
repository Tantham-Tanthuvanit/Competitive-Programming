// REWRITE PROBLEM USING BFS INSTEAD BECAUSE IT NEEDS SHORTST PATH

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef pair<int,int> pii;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(vector<vector<char>>& grid, pii start) {

}

int main() {
	speed

	int n,m; cin >> n >> m;
	pii start, end;

	vector<vector<char>> grid(n,vector<char>(m));	
	vector<vector<bool>> visited(n,vector<bool>(m,false));

	for (int i = 0; i < n; ++i)
		for (int v = 0; v < m; ++v) {
			cin >> grid[i][v];
			if (grid[i][v] == 'A') {
				start.first = i;
				start.second = v;
			}
		}

	bool found = false;
	int distance = 1;

	dfs(start,grid,visited,found,distance);

	found ? cout << "YES" : cout << "NO";
	found ? cout << distance : cout << 

	return 0;

}
