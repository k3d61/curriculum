//
// Created by kedar on 18/6/19.
//

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
long maxSum;

bool toPrint = true;
#define pout if(toPrint) cout


// Complete the cost function below.
int cost(vector<int> B) {
    int dp[ 2 ][B.size()];
    dp[0][0] = B[0];
    dp[1][0] = 1;
    maxSum = 0;

    pout << "\t";
    for(int i =1 ; i < B.size() ; i++ ){
        long one = max(abs( 1 - dp[0][ i-1 ] ), abs( 1 - dp[1][i-1] ) );
        long two =  max(abs( B[i] - dp[0][ i-1 ] ), abs( B[i] -dp[1][i-1] )) ;
        dp[0][i]  = two;
        dp[1][i] = one;

        maxSum += max(one,two );
        pout << max(one, two) << "\t";
    }

    pout << endl;
    for(int i=0 ; i< B.size() ;i++ ){
        pout << dp[0][i] << "\t";
    }
    pout << endl;
    for(int i=0 ; i< B.size() ;i++ ){
        pout << dp[1][i] << "\t";
    }
    pout << endl;
    return maxSum;
}

int main()
{
    int t;
    cin >> t;

    while(t-- > 0) {
        int n;
        cin >> n;

        vector<int> B(n);

        for (int i = 0; i < n; i++) {
            int B_item ;
            cin >> B_item;
            B[i] = B_item;
        }
        int result = cost(B);
        cout << result << "\n";
    }
    return 0;
}
