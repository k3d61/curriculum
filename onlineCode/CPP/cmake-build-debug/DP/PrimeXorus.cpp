//
// Created by kedar on 30/6/19.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long

bool toPrint  = false;

#define pout if(toPrint) cout

vector<LL> prime;
vector<int> isPrime( 1000000+1, true);

LL gmax;

void isPrimeNo(){

    long long b = gmax;
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= b; ++i) {
          if(isPrime[i]) {
            prime.push_back(i);
        }
        for (int j = 2; j*i <= b; ++j) {
            isPrime[i*j] = false;
        }
    }
}

#include <bitset>
LL printRange(LL a, LL b){

   /* pout << "all Primes " << endl;
    for (int k = a; k <= b; ++k) {
        pout << k << " = " << isPrime[k] << endl;
    }
    pout  << endl;
    */
    auto itl = lower_bound(prime.begin(), prime.end(), a);
    auto itu = upper_bound(prime.begin(), prime.end(), b);
    pout << "lower bound = " << *itl << endl;
    pout << "upper bound = " << *itu << endl;
    pout << "diff = " << itu-itl << endl;

    LL min = 1000000;
    for (int k = 0; k < itu-itl; ++k) {
        pout << *(itl+k)  << "\t";

    }
    pout << endl;

    for (int k = 1; k < itu-itl; ++k) {
        LL temp = bitset<64>(*(itl+k)^(*(itl+k-1))).to_ullong();
        if (temp < min)
            min = temp;
        //pout <<"xor = "<< temp << endl;

    }
    pout << endl;
    return min;
}
int main() {

    int n, N;
    cin >>n;

    vector<LL> one;
    vector<LL> two;

    N = n;
    LL i = 0;
    LL max = 0;
    while(n--){
        long long a,b;
        cin >> a >> b;

        one.push_back(a);
        if ( max < a )
            max = a;

        two.push_back(b);
        if ( max < b )
            max = b;

    }
    gmax = max+10;
    isPrimeNo();


    n=N;
    i=0;
    while(n--) {
        long long a,b;

        a = one[i];
        b = two[i];
        i++;
        LL count = 0;
        for (int j = a; j <=b ; ++j) {
            if (isPrime[j])
                count++;
        }
        pout << endl;
        LL ret = printRange(a, b);
        pout <<"{" << a << " , " << b <<"}, counter = " << count << endl;
        if (count < 2) {
            cout << -1 << endl;
            continue;
        }
        cout << ret << endl;
    }
    return 0;
}
