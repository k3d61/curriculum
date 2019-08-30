//
// Created by kedar on 11/7/19.
//

bool toPrint = true;
#define pout if(toPrint) cout
#define LL long long

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int q;
    cin >> q;
    vector<int> arr(q,0);
    vector<vector<int>> dp(10000+1, arr);
    int max = 0;

    for (int i = 0; i < q; ++i) {
        int a, b, val;
        cin >> a >> b >> val;
        pout << a << " " << b << " " << val << endl;
        if( a > b ){
            int temp = b;
            b = a;
            a = temp;
        }
        if(a>max) max = a;
        if(b>max) max = b;
        for (int j = a; j <= b; ++j) {
            dp[j][i] = val;
        }
    }
    pout << "dp = " << endl;

    for (int k = 1; k <= max ; ++k) {
        for (auto i = dp[k].begin() ; i < dp[k].end() ; ++i) {
            pout << *i << " " ;
        }
        pout << endl;
    }
    pout << endl;

    int min = 0;
    for (int k = 1; k <= max ; ++k) {

        sort( dp[k].begin(), dp[k].end() );
        int temp = 0;
        int q_max = q;
        if(dp[k][0] != 0){
            q_max = q-1;
        }

        int qi = 0;
        auto it = dp[k].begin();

        while( qi < q_max){
            pout << *it << " " ;
                temp += *it;
                it++;
                qi++;
        }
        if(temp > min)
            min = temp;
        pout << " = " << temp << endl;
    }

    cout << min << endl;
    return 0;
}
