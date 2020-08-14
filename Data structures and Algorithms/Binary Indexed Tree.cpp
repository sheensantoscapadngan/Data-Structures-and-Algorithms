#include <bits/stdc++.h>

using namespace std;

int BIT[1001],n,q,arr[1001];

void update(int x, int val){
	for(;x <= n; x += x&-x)
		BIT[x] += val;
}

int query(int x){
	int sum = 0;
	for(;x > 0; x -= x&-x)
		sum += BIT[x];
	return sum;
}

int main(){
	memset(BIT,0,sizeof(BIT));
	 cin >> n >> q;
	 for(int x = 0; x < n; x++){
	 	cin >> arr[x];
	 	update(x+1,arr[x]);
	 }
	 for(int x = 0; x < q; x++){
	 	int a,b;
	 	cin >> a >> b;
	 	cout << query(b) - query(a-1) << endl;
	 }
}
