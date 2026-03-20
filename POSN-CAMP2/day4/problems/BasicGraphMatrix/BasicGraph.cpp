#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> graph;
vector<bool> visited;
void dfs(int key)
{  
	visited[key] = true;
	cout << key << ' ';
	for(int i=0;i<graph.size();i++){
		 if(graph[key][i]!=0&&!visited[i])
		 dfs(i);
	}
}
void bfs(int key)
{
	vector<bool> v2(n,false);
	queue<int> q;
	
	v2[key] = true;
	q.push(key);
	while(!q.empty())
	{     int node = q.front();
	      q.pop();
	      cout << node << ' ';
	      for(int i=0;i<n;i++)
		  {
	      	if(graph[node][i]!=0&&!v2[i]){
	      		v2[i]=true;
	      		q.push(i);
			  }
		  }
		
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
    	vector<int> l;
    	for(int j=0;j<n;j++){
    		l.push_back(0);
		}
		graph.push_back(l);
	}
    while(true){
    	char cmd;
    	cin >> cmd;
    	if(cmd == 'e')
		{
    		int u,v,w;
    		cin >> u >> v >> w;
    		graph[u][v] = w;
		}
		else break;
	}
	while(true){
    	char cmd;
    	cin >> cmd;
    	visited.assign(n, false);
    	if(cmd == 'd')
		{
    		int start;
    		cin >> start;
    		dfs(start);
    		cout << endl;
		}
		else if(cmd == 'b')
		{
    		int start;
    		cin >> start;
    		bfs(start);
    		cout << endl;
		}
		else break;
	}
    
}
