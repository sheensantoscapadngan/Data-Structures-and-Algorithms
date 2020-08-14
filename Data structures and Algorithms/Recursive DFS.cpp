#include <bits/stdc++.h>

using namespace std;

bool visited[10001];
vector<vector<int>> g;

void dfs(int node){
	visited[node] = true;
	cout << node << " ";
	for(int x = 0; x < g[node].size(); x++){
		if(!visited[g[node][x]]){
			dfs(g[node][x]);
		}
	}
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
	for(int x = 1; x <= n;  x++){
		cout << "YEP"
		if(!visited[x]){
			dfs(x);
			cout << endl;
		}
	}
}
