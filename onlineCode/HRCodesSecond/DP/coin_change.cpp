#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> coins;
int n;
long long INF = 1e7;
vector<int> dp;
// this is varient of coin change
// it gives minimum coins needed to make that coin change

int solve(int N){

	if(n == N) return 0;
	if( N > n) return INF;
	if( dp[N] != -1 ) return dp[N];

	int count  = 0;
	int ans = INF;
	for(auto i = coins.begin() ; i != coins.end() ; i++){
		// cout << *i << endl;
		int temp = solve(N + *i)+1;
		if( ans > temp )
			ans = temp;
		// cout << N << " == " << temp  << " " << ans<< endl;
	}
	dp[N] = ans;
	return ans;
}
int main(){
	dp.resize(1000);
	for (int i = 0; i < dp.size(); ++i)
	{
		dp[i]=-1;
	}
	coins.push_back(1);
	coins.push_back(2);
	// coins.push_back(3);
	coins.push_back(5);
	coins.push_back(10);
	coins.push_back(50);
	coins.push_back(100);
	int N;
	cin >> N;
	n = N;
	cout << solve(0) << endl;

	return 0;
}

