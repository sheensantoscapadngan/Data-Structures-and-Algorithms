#include <bits/stdc++.h>

using namespace std;

vector<int> factor;

int main(){
	int n,copy;
	cin >> n;
	copy = n;
	for(int x = 2; x < n; x++){
		while(copy%x == 0){
			factor.push_back(x);
			copy /= x;
		}
	}
	if(copy != 1) factor.push_back(copy);
	for(int x : factor)
		cout << x << " ";
	cout << endl;
}
