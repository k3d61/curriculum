//
// Created by kedar on 25/8/19.
// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edb/00000000001707b8

#include<bits/stdc++.h>
using namespace std;

//#define flag 1
#define toPrint 1

#ifdef flag
#define pout(x) cout << x
#else
#define pout(x)
#endif

string solve(){

    int D, S;
    cin  >> D >> S;
    long long sumC=0, sumE=0;
    string ret;
    for(int i = 0 ; i < S ; i++){
        int a, b;
        cin  >> a  >> b;
        sumC += a;
        sumE += b;
    }
    float sc = (float)sumC * (float)(1/(double)S);
    float se = (float)sumE * (float)(1/(double)S);

    pout( "sumC=" << sumC << " sumE= " << sumE << " sumC*(1/S)=" << sc <<" sumE*(1/S)=" << se << endl);
    for (int j = 0; j < D; ++j) {
        int a, b;
        cin >> a >> b;
        pout( j+1 << " = " << a << " " << b << endl);

        if(a > sumC || b > sumE)
            ret.append(1u,'N');
        else if( a > sc && b > se ){
            ret.append(1u, 'N');
        } else
            ret.append(1u, 'Y');

    }
    return ret;
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

/*

1
4 2
3 8
6 10
0 18
3 13
10 0
7 3
*/
