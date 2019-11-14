#include <bits/stdc++.h>

using namespace std;


#define ll long long
vector<ll> in;
void solve(){
	int n;
	cin >>n;

	in.resize(n,0);
	for(int i=0 ; i < n ; i++){
		cin >> in[i];
	}
	for(int i=0 ; i < n ; i++){
		cout << in[i] << " " ;
	}
	cout << endl;
	int maxtill = 0;

	int ans = 0;
	int tempsum = 0;

	for(int i = 0 ; i < n; i++){
		if(in[i] >= maxtill){
			ans += tempsum;
			tempsum = 0;
			maxtill = in[i];
			cout << "max" << maxtill << endl;
			
		}
		else{
			cout << "add " << maxtill - in[i] << endl;
			tempsum += maxtill - in[i];
		}
	}
	cout << endl << ans<< endl;
	maxtill = 0;
	tempsum = 0;
	for(int i = n-1 ; i >= 0; i--){
		if(in[i] > maxtill){
			ans += tempsum;
			tempsum = 0;
			maxtill = in[i];
			cout << "max" << maxtill << endl;
			
		}
		else{
			cout << "add " << maxtill - in[i] << endl;
			tempsum += maxtill - in[i];
		}
	}
	cout << endl << "ans = "<< ans<< endl;
	
}
int main(){

	int t;
	cin >> t;
	while(t--) solve();
	return 0;

}