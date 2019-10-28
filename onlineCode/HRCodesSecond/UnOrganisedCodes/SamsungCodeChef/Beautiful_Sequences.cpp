#include <bits/stdc++.h>

#define ll long long 

using namespace std;

vector<ll> input;
int N , P;


ll geti(ll i, ll j){
	if(i == -1)
		return input[j];
	return input[i];
}

/*

1
6 3 5
9 8 7 1 5 6

*/
ll dp[1000][1000][10] ;

ll solvedp(ll prev, ll i, ll k){

	
	if( k <= 0 ){

		return 1;
	}
	if( i >= N ){
		return 0;
	}
	if(dp[prev+1][i+1][k+1] != -1){
		return dp[prev+1][i+1][k+1];
	}
	ll sum = 0;
	if( abs(geti(prev, i)-geti(i, i)) <= P ){
		
		sum += solvedp(i, i+1, k-1 );
		cout << "p less --> " << prev << " " << i << " " << k <<" sum = "<< sum<< endl;
		
	}
	if( abs(geti(prev, i)-geti(i, i)) > P ){
		cout << "p more --> " << prev << " " << i << " " << k <<" sum = "<< sum<< endl;
		dp[prev+1][i+1][k+1] = 0;
		return 0;
	}
	sum += solvedp(prev, i+1, k);
	cout << "--> " << prev << " " << i << " " << k <<" sum = "<< sum<< endl;
	
	dp[prev+1][i+1][k+1] = sum;
	return sum;
}

void solve(){
	ll n, k, p;
	cin >> n >> k >> p;

	N = n;
	P = p;
	input.clear();
	input.resize(n);

	for(int i=0 ; i< 1000 ; i++)
		for(int j=0 ; j< 1000 ; j++)
			for(int k=0 ; k < 10 ; k++)
				dp[i][j][k] = -1;

	for(ll i = 0 ; i < n ; i++){
		cin >> input[i];
	}
	sort(input.begin(), input.end());

	
	cout << "ret = " << solvedp(-1, 0, k) << endl;
}

int main(){

	int t;
	cin >> t;
	while(t--){ solve(); }
	return 0;
}