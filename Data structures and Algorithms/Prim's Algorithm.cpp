#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<pair<int,int>>> g;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
bool visited[10001];

int main(){
	int n,m;
	cin >> n >> m;
	bool flag = true;
	g.resize(n+1);
	memset(visited,false,sizeof(visited));
	for(int x = 0; x < m; x++){
		int a,b,c;
		cin >> a >> b >> c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	int node = 1,visitedNode = 0,sum = 0;
	while(visitedNode < n){
		if(visited[node]){
			flag = false;
			break;
		}
		visited[node] = true;
		visitedNode++;
		for(int x = 0; x < g[node].size(); x++){
			 pq.push({g[node][x].second,g[node][x].first});
		}
		while(!pq.empty() && visited[pq.top().second])
			pq.pop();
		sum += pq.top().first;
		node = pq.top().second;
		pq.pop();
	}
	if(flag) cout << "MST WEIGHT IS " << sum << endl;
	else cout << "GRAPH IS NOT CONNECTED" << endl;
	
}	
