//
// Created by kedar on 24/6/19.
//

#include <iostream>
#include <vector>

using namespace std;


bool toPrint = true;
#define pout if(toPrint) cout
int ssIterative( vector<int> arr, int k ){
    bool dp[ arr.size() ][ k+1 ] ;
    for(int i=0 ; i<= arr.size() ; i++ )
        dp[i][0] = true;
    for(int j = 1 ; j<= k ; j++ )
        dp[0][j] = false;



    for(int i = 1 ; i<= arr.size() ; i++ ){
        for(int j = 1 ; j<= k ; j++ ) {
            if( j< arr[ i ] )
                dp[ i ][ j ] = dp[ i-1 ][ j-1 ];
            else{
                dp[ i ][ j ] = dp[ i-1 ][ j ] || dp[ i-1 ][ j-arr[i] ];
            }
        }
    }

    for(int j = 0 ; j<= k ; j++ ) {
        pout << j << "\t";
    }
    pout << endl;
    for(int i=0 ; i<= arr.size() ; i++ ){
        for(int j = 0 ; j<= k ; j++ ){
            pout << dp[i][j] << "\t" ;
        }
        pout << endl;
    }
    pout << endl;
    return dp[ arr.size() ][ k ];

}


int main() {

    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        vector<int> arr;
        int sum = 0;
        for(int i=0 ; i<n ; i++){
            int temp;
            cin >> temp;

            sum += temp;
            arr.push_back(temp);
        }
        if(sum % 2 != 0){
            cout <<"NO"<< endl;
            continue;
        }
        if ( ssIterative(arr,10 ))
            cout << "YES"<< endl;
        else
            cout << "NO"<< endl;
    }
	return 0;
}

/*
1
4
1 5 11 5
 * */