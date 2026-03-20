#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> graph;
vector<vector<bool>> visited;

int dfs(int x ,int y){
    if(x<0||x>=n||y<0||y>=m) return 10000;
    if(graph[x][y]=='#') return 10000;
    if(visited[x][y]) return 10000;
    if(graph[x][y]=='E') return 1;

    visited[x][y] = true;

    int res = dfs(x,y+1) || dfs(x+1,y) || dfs(x,y-1) || dfs(x-1,y);

    visited[x][y] = false;

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    graph.assign(n, vector<char>(m));
    visited.assign(n, vector<bool>(m, false));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
        }
    }

    cout << dfs(0,0);
}
