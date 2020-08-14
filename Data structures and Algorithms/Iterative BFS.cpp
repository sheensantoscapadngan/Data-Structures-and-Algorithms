#include <bits/stdc++.h>

using namespace std;

bool visited[10001];
vector<vector<int>> g;

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
		if(!visited[x]){
			queue<int> q;
			q.push(x);
			visited[x] = true;
			while(!q.empty()){
				int node = q.front();
				cout << node << " ";
				q.pop();
				for(int y = 0; y < g[node].size(); y++){
					if(!visited[g[node][y]]){
						visited[g[node][y]] = true;
						q.push(g[node][y]);
					}
				}
			}
			cout << endl;
		}
	}
}
