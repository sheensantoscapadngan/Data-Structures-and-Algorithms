#include <bits/stdc++.h>

using namespace std;

int n,arr[10001],tree[10001];

int query(int node, int left, int right, int l, int r){
	if(left > r || right < l)
		return 0;
	else if(l <= left && r >= right){
		return tree[node];
	}
	int mid = (left+right)/2;
	int sumLeft = query(2*node+1,left,mid,l,r);
	int sumRight = query(2*node+2,mid+1,right,l,r);
	return sumLeft + sumRight;
}
void buildTree(int node, int left, int right){
	if(left == right){
		tree[node] = arr[left];
		return;
	}
	int mid = (left+right)/2;
	buildTree(2*node+1,left,mid);
	buildTree(2*node+2,mid+1,right);
	tree[node] = tree[2*node+1]+tree[2*node+2];
}	
void update(int node, int left, int right, int pos, int new_val){
	if(left > pos || right < pos)
		return;
	if(left == right){
		tree[node] = new_val;
		return;
	}
	int mid = (left+right)/2;
	update(2*node+1,left,mid,pos,new_val);
	update(2*node+2,mid+1,right,pos,new_val);
	tree[node] = tree[2*node+1] + tree[2*node+2];
}

int main(){
	int q;
	cin >> n >> q;
	memset(tree,0,sizeof(tree));
	for(int x = 0; x < n; x++) cin >> arr[x];
	buildTree(0,0,n-1);
	while(q--){
		int a,b,c;
		cin >> c;
		cin >> a >> b;
		if(c == 1){
			a--,b--;
			cout << query(0,0,n-1,a,b) << endl;	
		}else{
			b--;
			update(0,0,n-1,b,a);
		}
	}
}
