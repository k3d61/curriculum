//
// Created by kedar on 22/8/19.
//
/*

4
1 3
2 6
8 10
15 18

4
1 3 2 4 6 8 9 10

4
6 8 1 9 2 4 4 7

 */

#include<bits/stdc++.h>
using namespace std;

#define flag 1
#define toPrint 1

#ifdef flag
#define pout(x) cout << x
#else
#define pout(x)
#endif


int main(){

    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for(int i = 0 ; i < n ; i++ ){
        int a, b;
        cin >> a >> b;
        arr.push_back( make_pair(a,b) );
    }

    sort(arr.begin(), arr.end());

    int a = arr[0].first,
        b = arr[0].second;
    pout ( a << " ");

    for(int i = 1 ; i < n ; i++ ){
//        pout ( arr[i].first << " = " << arr[i].second << endl );
        if( arr[i].first <= b ){
            if( b < arr[i].second ){
                b = arr[i].second;
            }
        }
        if( arr[i].first > b ){
            pout ( b << " ");
            a = arr[i].first;
            b = arr[i].second;
            pout ( a << " ");
        }

    }
    pout ( b << endl);


    return 0;
}