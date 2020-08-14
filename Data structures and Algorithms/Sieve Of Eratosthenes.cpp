#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> primes;
	bool isPrime[100001];
	memset(isPrime,true,sizeof(isPrime));
	int n;
	cin >> n;
	for(int x = 2; x <= sqrt(n); x++){
		if(isPrime[x]){
			for(int y = 2*x; y <= n; y += x){
				isPrime[y] = false;
			}
		}
	}
	for(int x = 2; x < n; x++){
		if(isPrime[x]){
			primes.push_back(x);
		}	
	}
	for(int x : primes)
		cout << x << " ";
	cout << endl;
}
