#include <bits/stdc++.h>

using namespace std;

int n,arr[10001],tree[10001],lazy[10001];

int query(int node, int left, int right, int l, int r){
	if(lazy[node] != 0){ 	
		tree[node] += lazy[node];
		if(left != right){
			lazy[2*node+1] = lazy[node];
			lazy[2*node+2] = lazy[node];
		}
		lazy[node] = 0;
	}
	if(left > r || right < l) return 0;
	else if(l <= left && r >= right) return tree[node];
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
void update(int node, int left, int right, int l, int r, int new_val){
	if(lazy[node] != 0){
		tree[node] += lazy[node];
		if(left != right){
			tree[2*node+1] += lazy[node];
			tree[2*node+2] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(left > r || right < l) return;
	if(left >= l && right <= r){
		tree[node] += (r-l+1)*new_val;
		if(left != right){
			lazy[2*node+1] += new_val;
			lazy[2*node+2] += new_val;
		}
		return;	
	}	
	int mid = (left+right)/2;
	update(2*node+1,left,mid,l,r,new_val);
	update(2*node+2,mid+1,right,l,r,new_val);
	tree[node] = tree[2*node+1] + tree[2*node+2];
}

int main(){
	int q;
	cin >> n >> q;
	memset(tree,0,sizeof(tree));
	memset(lazy,0,sizeof(lazy));
	for(int x = 0; x < n; x++) cin >> arr[x];
	buildTree(0,0,n-1);
	while(q--){
		for(int x = 0; x < 3*n; x++){
			cout << tree[x] << " ";
		}
		cout << endl;
		int a,b,c;
		cin >> c;
		if(c == 1){
			cin >> a >> b;
			a--,b--;
			cout << query(0,0,n-1,a,b) << endl;	
		}else{
			int l,r,v;
			cin >> l >> r >> v;
			l--,r--;
			update(0,0,n-1,l,r,v);
		}
	}
}
