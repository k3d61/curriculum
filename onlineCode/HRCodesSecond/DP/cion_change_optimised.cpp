#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> coins;
int n;
long long INF = 1e7;
vector<int> dp;
vector<int> ret;
// this is varient of coin change
// it gives all coins needed to make that
// coin change
int retIndex = 0;
void solve(int N, int index, int retIndex){
	if( N < 0) return;
	if(N == 0) {
		cout << endl;
		for(int i=0 ; i < ret.size() ; i++){
			cout << ret[i] << " ";
		}
			return;
	}
	if(index >= coins.size()) return;
	// for(int i = index ; i < coins.size() ; i++ ){
			ret.push_back( coins[index] );
			// ret[retIndex] = coins[i];
			
			solve( N-coins[index], index , retIndex+1);
			
			ret.pop_back();
			solve( N, index+1 , retIndex);
	// }

}
int main(){
	// dp.resize(1000);

	for (int i = 0; i < dp.size(); ++i)
	{
		dp[i]=-1;
	}
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(5);
	coins.push_back(10);
	coins.push_back(50);
	coins.push_back(100);
	int N;
	cin >> N;
	n = N;
	// ret.resize(n+1, 0);
	solve(N, 0, 1);

	return 0;
}

