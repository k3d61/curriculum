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

ll solvedp(ll prev, ll i, ll k){

	
	if( k <= 0 )
		return 1;
	if( i >= N )
		return 0;
	ll sum = 0;
	if( abs(geti(prev, i)-geti(i, i)) <= P ){
		
		sum += solvedp(i, i+1, k-1 );
		cout << "p less --> " << prev << " " << i << " " << k <<" sum = "<< sum<< endl;
		
	}
	if( abs(geti(prev, i)-geti(i, i)) > P ){
		cout << "p more --> " << prev << " " << i << " " << k <<" sum = "<< sum<< endl;

		return 0;
	}
	sum += solvedp(prev, i+1, k);
	cout << "--> " << prev << " " << i << " " << k <<" sum = "<< sum<< endl;
	return sum;
}

void solve(){
	ll n, k, p;
	cin >> n >> k >> p;

	N = n;
	P = p;
	input.clear();
	input.resize(n);

	sort(input.begin(), input.end());
	for(ll i = 0 ; i < n ; i++){
		cin >> input[i];
	}

	cout << "ret = " << solvedp(-1, 0, 2) << endl;
}

int main(){

	int t;
	cin >> t;
	while(t--){ solve(); }
	return 0;
}