//
// Created by kedar on 11/7/19.
//


bool toPrint = false;
#define pout if(toPrint) cout
#define LL long long

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define one '1'
#define zero '0'
#define toggle(val) val==one?zero:one
string s;
int len;
LL cost(int i, char val){

    pout << i << " " << val << endl;
    if(s[i] == val) {
        pout << "\t\t, same val" << endl;
        return 0;
    }
    if(i == len-1 ) {
        s[i] = toggle(s[i]);
        pout << "\t\t, last element, " << s << endl;

        return 1;
    }
    LL sum = 1;
    sum += cost(i+1, one );
    for (int j = i+2; j < len ; ++j) {
        sum += cost(j, zero);
    }
    s[i] = toggle( s[i] );

    return sum;
}

int main() {


    cin >> s;
    LL sum = 0;
    len = s.length();
    for (int i = 0; i < s.length() ; ++i) {
        if(s[i] !=0 )
            sum += cost(i, zero);
    }
    cout << sum << endl;
    return 0;
}
