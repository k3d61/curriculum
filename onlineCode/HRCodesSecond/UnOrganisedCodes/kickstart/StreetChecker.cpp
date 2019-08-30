//
// Created by kedar on 25/8/19.
// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edb/00000000001707b9



#include<bits/stdc++.h>
using namespace std;

//#define flag 1
#define toPrint 1

#ifdef flag
#define pout(x) cout << x
#else
#define pout(x)
#endif

string solve() {
    long long l, r;
    cin >> l >> r;

    long long evenMul[r + 1];
    long long oddMul[r + 1];
    bool visited[r] ;

    for (long long  i = l; i < r ; i++){
        for(long long j = 1 ; j < sqrt(i); j++ ){
            if( j%2 == 0 )
                evenMul[i] ++;
            else
                oddMul[i]++;
        }
    }

}

int main(){

    int t;
    cin >> t;
    int i=1;

    while( i <= t) {
        string ret = solve() ;
        cout << "Case #" << i << ": " << ret << endl;

        i++;
    }



    return 0;
}

