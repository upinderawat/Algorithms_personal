#include <bits/stdc++.h>
using namespace std;
#define ll long long

//DP: T.c O(n*r)
//	  S.C O(n*r)
/*
ll ncr(ll n, ll r){
	ll C[n+1][r+1];
	for(ll i = 0; i<= n; i++){
		for(ll j = 0; j<= min(i,r); j++){
			if(j == 0 || j == i){
				C[i][j] = 1;
			}
			else{
				C[i][j] = C[i-1][j-1] + C[i-1][j];
			}
		}
	}
	return C[n][r];
}
*/
//DP: T.C O(n*r)
//	  S.C O(r)
ll ncr(ll n, ll r){
	ll C[r+1];
	for(ll i = 0; i<= n; i++){
		for(ll j = min(i,r); j>= 0; j--){
			if(j == 0 || j == i)
				C[j] = 1;
			else
				C[j] = C[j] + C[j-1];
		}
	}
	return C[r];
}


int main(){
	ll n,r;
	int T;
	cin>>T;
	while(T--){
		cin>>n>>r;
		cout<<ncr(n,r)<<"\n";
	}
	return 0;
}