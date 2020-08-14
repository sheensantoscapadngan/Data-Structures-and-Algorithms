#include <bits/stdc++.h>

using namespace std;

int dsu[10001],size[10001];

int root(int node){
	while(node != dsu[node])
		node = dsu[node];
	return node;
}
int join(int a, int b){
	a = root(a);
	b = root(b);
	if(size[a] <= size[b]){
		dsu[a] = b;
		size[b] += size[a];
	}else{
		dsu[b] = a;
		size[a] += size[b];
	}
}
int find(int a, int b){
	a = root(a);
	b = root(b);
	if(a == b)
		return true;
	else 
		return false;
}
int main(){
	int n;
	cin >> n;
	for(int x = 0; x < n; x++){
		dsu[x] = x;
		size[x] = 1;
	}
}
