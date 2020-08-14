#include <bits/stdc++.h>

using namespace std;

int power(int n, int b){
	
	if(b == 0) return 1;
	int res = power(n,b/2);
	if(b % 2)
		return res * res * n;
	else 
		return res * res;
	
}

int powerLoop(int n, int b){
	
	int res = 1,mult = 1;
	while(b > 0){
		
		if(b & 1)
			res *= n;

		n *= n;
		b /= 2;
	}
		
	return res;
	
}


int main(){
	
	int n,b;
	cin >> n >> b;
	cout << powerLoop(n,b) << endl;
	
}
