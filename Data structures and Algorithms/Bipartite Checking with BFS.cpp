#include <bits/stdc++.h>

using namespace std;

bool visited[10001];
vector<vector<int>> g;

bool bfs(int node){
	int color[1001];
	memset(color,-1,sizeof(color));
	queue<int> q;
	q.push(node);
	visited[node] = true;
	color[node] = 1;
	
	while(!q.empty()){
		node = q.front();
		q.pop(); 
		int nodeColor = color[node];
		for(int x = 0; x < g[node].size(); x++){
			if(!visited[g[node][x]] && color[g[node][x]] == -1){
				visited[g[node][x]] = true;
				color[g[node][x]] = !nodeColor;
				q.push(g[node][x]);
			}
			else if(nodeColor == color[g[node][x]])
				return false;
		}
	}
	return true;
}

int main(){
	
	int n,m;
	memset(visited,false,sizeof(visited));
	cin >> n >> m;
	g.resize(n+1);
	for(int x = 0; x < m; x++){
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if(bfs(1)){
		cout << "YES" << endl;
	}else cout << "NO" << endl;
}
