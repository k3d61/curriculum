//
// Created by kedar on 30/8/19.
//

#include <bits/stdc++.h>

using namespace std;

//#define flag 1
#define toPrint 0

#ifdef flag
#define pout(x) cout << x
#else
#define pout(x)
#endif

int main(){

    int t, T; cin >> t;
    T = t;
    long max = 0;
    long min = 1e5;

    set<long> ar;
    vector<long> inp;

    t=T;
    while(t--) {
        int temp;
        cin >> temp;
        inp.push_back(temp);
        if(max < temp) max = temp;
        if(min > temp) min = temp;
    }

    if(toPrint)
    for(int i=0 ; i < inp.size() ;i++) {
        pout( inp [i] << " ");
    }
    for (int i = min; i < max-min+T+1; ++i) {
        ar.insert(i);
    }


    for(int i=0 ; i < inp.size() ;i++){
        int temp = inp[i];
         auto ub = lower_bound(ar.begin(), ar.end(), temp);
//         pout(temp << " erasing : " << *ub << endl);
         ar.erase(*ub);
         cout << *ub << "\n";
    }
}