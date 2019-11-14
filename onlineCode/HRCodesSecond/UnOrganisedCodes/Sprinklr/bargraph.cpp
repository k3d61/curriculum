#include <bits/stdc++.h>

using namespace std;
#define ll long long
#include <vector>
#include <deque>

void solve(){


	ll n,k; cin >> n>>k;

	vector<ll> in(n);
	cout <<k <<endl;
	for(int i = 0 ;  i < n; i++){
		cin  >> in[i];
	}
	ll window = n-k;
	sort(in.begin(), in.end());
	for(int i = 0 ;  i < n; i++){
		cout << in[i] << " ";
	}
	cout << endl;
	deque<pair<ll,ll>> pair_diff;
	ll min = 1e7;
	// for forst window
	for(int i = 1 ; i < window; i++){

		cout << ">>" << in[i] << endl;
		ll diff = in[i] - in[i-1];
		ll front = pair_diff.front().first;
	
		if( pair_diff.empty() || diff < front ){
			cout << "push " << diff << endl;
			pair_diff.push_back(make_pair( diff, i-1) );

		}
		else{
			while( !pair_diff.empty() ){
				cout << "pop " << pair_diff.back().first << endl;
				pair_diff.pop_back();
			}
			cout << "push " << diff << endl;
			pair_diff.push_back( make_pair( diff, i-1) );
		}

	}
	min = pair_diff.front().first;
	cout <<"-- " <<min << endl;

	for(int i = window ; i < n ; i++){
		cout << ">>" << in[i] << endl;
		
		ll window_from = i - (window-1);
		cout << "window start = " << window_from << " ";
		ll diff = in[i] - in[i-1];
		ll front = pair_diff.front().first;
		cout << "front expiry = " << pair_diff.front().second << endl;
		// remove elment from last window
		if( !pair_diff.empty() && pair_diff.front().second < window_from ) {
			cout << "pop " << pair_diff.front().first << endl;
			pair_diff.pop_front();
		}
		

		if( pair_diff.empty() || diff < front ){
			cout << "push " << diff << endl;
			pair_diff.push_back(make_pair( diff, i-1) );

		}
		else{
			while( !pair_diff.empty() ){
				cout << "pop " << pair_diff.back().first << endl;
				pair_diff.pop_back();
			}
			cout << "push " << diff << endl;
			pair_diff.push_back( make_pair( diff, i-1) );
		}
		if( pair_diff.front().first < min)
			min = pair_diff.front().first;
	}
	cout <<"min = " << min << "\n---------"<< endl ;
}


/*
4
5 1
1 2 4 7 8
9 3
1 2 4 7 8 10 100 100 100
10 2
5 90 5 6 12 12 7 9 2 100
8 3
3 3 3 3 3 3 3 3
*/
int main(){

	int t ;
	cin >> t;
	while(t--)
	solve();

	return 0;
}