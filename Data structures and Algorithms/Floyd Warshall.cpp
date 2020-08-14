#include <bits/stdc++.h>

using namespace std;

int cost[100][100];

int main(){
	memset(cost,INT_MAX,sizeof(cost));
	int n,m;
	cin >> n >> m;
	for(int x = 1; x <= n; x++) cost[x][x] = 0;
	for(int x = 0; x < m; x++){
		int a,b,c;
		cin >> a >> b >> c;
		cost[a][b] = c;
	}
	for(int z = 1; z <= n; z++){
		for(int x = 1; x <= n; x++){
			for(int y = 1; y <= n; y++){
				if(cost[x][y] > cost[x][z]+cost[z][y])
					cost[x][y] = cost[x][z]+cost[z][y];
			}
		}
	}
}
