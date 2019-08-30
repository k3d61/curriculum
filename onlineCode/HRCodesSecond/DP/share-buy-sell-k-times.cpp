//
// Created by kedar on 5/7/19.
//

#include <iostream>
#include <vector>

using namespace std;

bool toPrint  = true;
#define pout if(toPrint) cout

int recur( vector<vector<int>> &dp, vector<int> arr, int n, int k ){

    pout << n << " : " << k << endl;
    if(n == 0 || k == 0 ){
        dp[n][k] = 0;
        return 0;
    }



    return 0;
}
int main(){

    int t;
    cin >> t;
    while(t--){

        int k, n;
        cin >> k >> n;
        vector<int> arr;
        for (int i = 0; i < n; ++i) {
            int tem;
            cin >> tem;
            arr.push_back(tem);
        }
        vector<int> row(k+1, -1);
        vector<vector<int>> dp(n+1, row);

        recur( dp, arr, n, k );

        for(int i=0 ; i < n+1 ; i++ ){
            for (int j = 0; j < k+1; ++j) {

                pout << dp[i][j] << "\t";
            }
            pout << endl;
        }

    }



    return 0;
}
/*

1
2
6
10 22 5 75 65 80

*/
