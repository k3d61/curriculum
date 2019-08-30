//
// Created by kedar on 25/8/19.
// https://www.geeksforgeeks.org/combinations-strings-can-used-dial-given-phone-number/

#include<bits/stdc++.h>
using namespace std;

#define flag 1
#define toPrint 1

#ifdef flag
#define pout(x) cout << x
#else
#define pout(x)
#endif

vector<string> arr {
         "0",
         "1", "ABC", "DEF",
          "GHI","JKL", "MNO",
          "PQRS", "TUV", "WXYZ"
};

void iterate( string &inp, int i, string forward ){
    if( i >= inp.length() )
        cout << forward << endl;

    for(int j = 0 ; j < arr[ inp[i]-'0' ] .length() ; j++ ){
        iterate( inp, i+1, forward + arr[ inp[i]-'0' ][j])  ;
    }

}

int main(){

    string inp;
    cin >> inp;

    string ret = "";
    iterate(inp, 0, ret);

    return 0;
}

