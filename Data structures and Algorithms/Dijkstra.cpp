#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> g;
int n,m;
//one to n

void search(){
	vector<int> dist(n+1),parent(n+1),visited(n+1,false);
	for(int x = 0; x < dist.size(); x++) dist[x] = INT_MAX;
	
	priority_queue<pair<int,int>> q;
	dist[1] = 0;
	parent[1] = 1;
	q.push({0,1});
	while(!q.empty()){
		int node = q.top().second;
		q.pop();
		if(visited[node]) continue;
		visited[node] = true;
		for(int x = 0; x < g[node].size(); x++){
			int next = g[node][x].first;
			if(dist[next] > dist[node]+g[node][x].second){
				dist[next] = dist[node]+g[node][x].second;
				parent[next] = node;
				q.push({-dist[next],next});
			}
		}
	}
	
	int node = n;
	vector<int> res;
	while(node != parent[node]){
		res.push_back(node);
		node = parent[node];
	}
	if(node != 1) cout << -1 << endl;
	else{
		reverse(res.begin(),res.end());
		cout << 1 << " ";
		for(int x : res)
			cout << x << " ";
	}
}

int main(){
	cin >> n >> m;
	g.resize(n+1);
	for(int x = 0; x < m; x++){
		int a,b,c;
		cin >> a >> b >> c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	search();
}
