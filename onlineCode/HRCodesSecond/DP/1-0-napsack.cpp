//
// Created by kedar on 3/7/19.
//

#include <iostream>
#include <vector>
using namespace std;

bool toPrint = false;
#define pout if(toPrint) cout
#define LL long long

int rec(vector<vector<int>> &dp, vector<int> va,  vector<int>  wa , LL n, LL w){

/*
    pout << n << "\t" << w << endl;
    if( w < 0  || n < 0)
        return 0;
    if( w == 0 || n == 0) {
        pout << "\t return 0" << endl;
        dp[n][w] = 0;
        return dp[n][w];
    }
    if(dp[n][w] != -1)
        return dp[n][w];
    if( wa[n-1] <= w ) {
        pout << "ola" << endl;
        dp[n][w] = max(rec(dp, va, wa, n - 1, w),
                       rec(dp, va, wa, n - 1, w - wa[n - 1]) + va[n - 1]
                        );
    } else
        dp[n][w] = rec(dp, va, wa, n - 1, w);
*/

    for (int i = 0; i < n+1 ; ++i) {
        for (int j = 0; j < w+1; ++j) {
            if (i==0 || j==0){
                dp[i][j] = 0;
            }
            else if( wa[i-1] <= j ){
                dp[i][j] = max( dp[ i-1 ] [ j-wa[i-1] ] + va[ i-1 ] ,
                                dp[ i-1 ] [ j ]
                                ) ;
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][w];
}
int main() {

    int t;
    cin >> t;
    while(t--){
        int n, w;
        cin >> n >> w;
        vector<int> va, wa;
        for(int i=0 ; i<n ;i++ ){
            int temp;
            cin >> temp;
            va.push_back(temp);
        }
        for(int i=0 ; i<n ;i++ ){
            int temp;
            cin >> temp;
            wa.push_back(temp);
        }

        vector<int> v(w+1, -1);
        vector<vector<int>> dp(n+1, v);

        pout << endl;

        cout << rec(dp, va, wa, n, w) << endl;

        for(int i=0 ; i < n+1 ; i++ ){
            for (int j = 0; j < w+1; ++j) {

                pout << dp[i][j] << "\t";
            }
            pout << endl;
        }

    }

    return 0;
}
/*

1
3
4
1 2 3
4 5 1

 */
