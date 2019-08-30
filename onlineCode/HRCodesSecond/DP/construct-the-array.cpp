//
// Created by kedar on 2/7/19.
//

#include <bits/stdc++.h>

using namespace std;

bool toPrint = true;
#define pout if(toPrint) cout
#define LL long long

LL first, last, K, N;

LL rec(LL n, LL next, LL prev){
    pout << n << " " << next << " " << prev << endl;

    if(( n == N && next == last ) && (prev != next)) {
        pout << "\t add 1" << endl;
        return 1;
    }
    if( n == N ) {
        pout << "\t return 0" << endl;
        return 0;
    }

    if( prev == next ) {
        pout << "\t +-1 " << endl;
        return 0;
    }



    LL sum=0;
    for(int i=1 ; i <= K ; i++){
      //  pout << "in for = " << i << endl;
        sum += rec(n+1, i, next );
    }
    return sum;
}

long countArray(int n, int k) {

    LL sum=0;
    for(int i=1 ; i <= K ; i++){
        pout << "in for = " << i << endl;
        sum += rec(2, i, first );
    }
    return sum;


}

int main()
{

    int n ;
    int k ;
    int x ;
    cin >> n >> k >> x;
    first = 1;
    last = x;
    K = k;
    N = n;
    long answer = countArray(n, k);

    cout << answer << "\n";

    return 0;
}

