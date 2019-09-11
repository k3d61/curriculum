#include <bits/stdc++.h>
// https://www.hackerrank.com/contests/coding-test-3-slot-1/challenges/climb-them-stairs/problem
using namespace std;

#include <vector>

int N, K;
vector<vector<int>> dparr;

int dp( int i, int k ){
    if (k > K           ) return 0;
    if (i >  N           ) return 0;
    if (i == N && k >= K ) return 1;
    if (dparr[i][k] != 0 ) return dparr[i][k];

    dparr[i][k] = dp(i+1, k+1) + dp(i+2, k+1) + dp(i+3, k+1);
    cout << i << " " << k << " " << dparr[i][k] << endl;    
    return dparr[i][k];
}

void solve(){
    int n, k;
    cin >> n >> k;
    N = n;
    K = k;
    
    dparr.clear();
    vector<int> rowv(k+1, 0);
    dparr.resize(n+1, rowv);

    int ret  = dp(0, 0);
    cout << endl << " <> " << ret << endl;
    
    for (int i = 0; i < n+1; ++i)
    {
        for (int j = 0; j < k+1; ++j)
        {
            cout << dparr[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){

    int t;
    cin >> t;
    while(t--) solve();    
    return 0;
}

/*
1 // t
4 2 // N K

compla

*/