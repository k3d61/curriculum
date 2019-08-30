//
// Created by kedar on 26/8/19.
// https://github.com/kaushal02/interview-coding-problems/blob/master/maxCoins.cpp

#include<bits/stdc++.h>
using namespace std;

#define flag 1
#define toPrint 1

#ifdef flag
#define pout(x) cout << x
#else
#define pout(x)
#endif

#define P 1
#define Q 5
#define R 10
#define S 25


vector<int> arr;
vector<int> val{ 1, 5, 10, 25};
vector<int> taken{ 0, 0, 0, 0};

void printTaken();

int recRemove(int price, int accumulator, int i){



    return 0;
}


int main(){

    int price, p , q, r, s;
    cin >> price >> p >> q >> r >> s;


    arr.push_back(p);
    arr.push_back(q);
    arr.push_back(r);
    arr.push_back(s);

    int accumolator = 0;

    int i = 0;
    for( ;  accumolator < price && i < 4 ; i++ ){
        for (int j = 0; accumolator < price && j < arr[i] ; ++j) {

            pout ( arr[i] << endl );
            accumolator += val[i] ;
            taken[i]++;
        }
    }

    pout ( endl <<"acc = " << accumolator);

    if( accumolator == price ){
        pout( "value found:" );
        printTaken();
    }
    recRemove(price, accumolator, i);

    return 0;
}

void printTaken() {
    pout(endl);
    for (int k = 0; k < 4 ; ++k) {
        pout( taken[k] << " " );
    }

}

/*

3 3 2 2 2

6 3 2 2 2

 */
