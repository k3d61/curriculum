//
// Created by kedar on 23/6/19.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int k = 15;
int dp[ 100+1][ 1000 +1 ] ={0};

bool toPrint = true;
#define pout if(toPrint) cout

void printarr(){
    for(int j = 0 ; j<= k ; j++ ) {
        pout << j << "\t";
    }
    pout << endl;

    for (int i = 0; i <= arr.size() ; ++i) {

        for (int j = 0; j <= k; ++j) {
            cout << dp[i][ j ] << "\t";
        }
        cout << endl;
    }
    pout << endl;

}

/*

bool ssIterative(){
    bool dp[ arr.size()+1 ][ k+1 ];

    for (int i = 0; i <= arr.size(); ++i) {
        dp[i][0] = true;
    }
    for (int j = 1; j <= k ; ++j) {
        dp[0][j] = false;
    }

    for (int i = 1; i <= arr.size() ; ++i) {
        for (int j = 1; j <= k; ++j) {
            if( j < arr[i-1] )
                dp[i][j] = dp[ i-1 ][ j ];
            else{
                dp[ i ][ j ] = dp [ i-1 ][ j ] || dp[ i-1 ][ j-arr[i-1] ];
            }
        }
    }

    for(int j = 0 ; j<= k ; j++ ) {
        pout << j << "\t";
    }
    pout << endl;

    for (int i = 0; i <= arr.size() ; ++i) {

        for (int j = 0; j <= k; ++j) {
            cout << dp[i][ j ] << "\t";
        }
        cout << endl;
    }
    return dp[ arr.size() ][ k ];
}
*/


bool ssRecursive( int i, int n){

    pout << n <<"\t" << i ;
    if( n < 0 || i < 0) {
        pout << " end" << endl;
        return 2;
    }
    if( dp[i][n] != 0 && arr[i] == n) {
        pout << " non zero" << endl;
        return dp[i][n];
    }
    pout << endl;
    int ret1 = ssRecursive( i-1 , n-arr[i-1] );
    int ret2 = ssRecursive( i-1, n );
    if( ret1 == 2 && ret2 == 2 ){
        dp[i][n] = 2;
    } else
        dp[i][n] = 1;


}


int main() {

    int t;
    cin >> t;
    while (t--) {
        arr.clear();
        int n;
        cin >> n;
//        vector<int> arr;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;

            sum += temp;
            arr.push_back(temp);
        }


        if (sum % 2 != 0) {
            cout << "NO" << endl;
            continue;
        }

        k = 11;
        for(int i=0 ; i<= arr.size() ; i++ )
            dp[i][0] = 1;
        for(int j = 1 ; j<= k ; j++ )
            dp[0][j] = 2;


        ssRecursive(arr.size(), k);
        if (dp[ arr.size() ][ k ])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    printarr();
    return 0;
}


