#include <bits/stdc++.h>
// https://www.hackerrank.com/contests/coding-test-3-slot-1/challenges/climb-them-stairs/problem
using namespace std;

#include <vector>

long long N, K;
long long INF = -1e9;

vector<long long> input;
vector<long long> output;

vector<vector<long long>> dp;

long long solvedp(long long prev,  long long i, long long k){
 
    if( i > N ) return 0;
    if( dp[i][k] != INF )return  dp[i][k];
    

    long long oneJump = INF;
    long long twoJump = INF;
    long long threeJump = INF;

    if( k < K ){
        oneJump = input[i] + solvedp(i, i+1, k+1);
        dp[i][0] = oneJump;
    }

    twoJump = input[i] + solvedp(i, i+2, k);
    threeJump = input[i] + solvedp(i, i+3, k);
    
    dp[i][1] = max(twoJump, threeJump);

    output[i] = max(oneJump, dp[i][1]);

    // cout << prev<<" -->\t" << i <<"("<< output[i] <<")"<< "\t\t\t" << oneJump << "\t\t\t" << twoJump << "\t\t\t" << threeJump << endl;

    return max(oneJump, dp[i][k]);

/*

7
1 100 20 -500 -2 -500 3

*/


    // return 0;
}

void solve(){
    long long n ;
    cin >> n;
    N = n;
    K = 1;

    input.clear();
    input.resize(n+1);

    dp.clear();
    vector<long long> row(K+1, INF);
    dp.resize(n+1, row );

    output.clear();
    output.resize(n+1, INF);

    for (long long i = 1; i < n+1; ++i) {
        cin >> input[i];
    }

    // cout << endl;
    long long ret  = solvedp(-1, 1, 0);
    cout << ret << endl;
    
    /*cout << "\noutput = " << endl;
    for (long long i = 1; i < n+1; ++i)
    {
        cout << i << "\t" <<dp[i][0] << "\t\t" << dp[i][1] << "\t\t" << output[i]<< endl;
    }*/

}
int main(){

    long long t = 1;
    // cin >> t;
    while(t--) solve();    
    return 0;
}

/*

7
1 100 20 -500 -2 -500 3

*/