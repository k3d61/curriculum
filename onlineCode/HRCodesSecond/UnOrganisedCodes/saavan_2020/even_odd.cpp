#include <bits/stdc++.h>

using namespace std;


#define ll long long
vector<ll> in;
void solve(){
	int n;
	cin >>n;

	in.resize(n+1,0);
	for(int i=1 ; i <= n ; i++){
		cin >> in[i];
	}
	for(int i=1 ; i <= n ; i++){
		cout << in[i] << " " ;
	}
	int even = 0;
	int odd = 0;
	vector<ll> acc(n+1);
	acc[0] = 0;
	for(int i=1 ; i <= n ; i++){
		if( in[i]%2 != 0 ){
			acc[i] = acc[even]+1;
			odd = i;
		}
		else {
			acc[i] = acc[odd]+1;
			even = i;	
		}

	}
	cout << endl;
	for(int i=0 ; i <= n ; i++){
		cout << acc[i] << " " ;
	}
	cout <<endl << even << " " << odd << endl;	
}
int main(){

	int t;
	cin >> t;
	while(t--) solve();
	return 0;

}