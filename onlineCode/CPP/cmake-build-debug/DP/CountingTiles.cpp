//
// Created by kedar on 20/6/19.
//

//1 n
//2 u
//3 [
//4 ]

#include <bits/stdc++.h>

using namespace std;

int m = 1, n = 2;
int match(int old, int newval){

    if( old == 0 && newval == 2  ){
        return 1;
    }
    if( old == 1 && newval == 3  ){
        return 1;
    } else
        return 0;
}
int rec(int i, int j, int val){
    cout << i <<  " : " << j << " = " << val << endl;


    int counter = 0;
    if( i >= m )
        return counter;
    if( j >= n )
        return  counter;

    for (int i = 0; i < 3; ++i) {
        counter += match(val, i);
        counter += rec( i, j+1, i);
    }
    for (int i = 0; i < 3; ++i) {
        counter += match(val, i);
        counter += rec( i+1, j, i);
    }
    return counter;
}
int main(){

    int counter = 0;
    for (int i = 0; i < 3; ++i) {
        counter += rec( 0,1, i);
    }
    for (int i = 0; i < 3; ++i) {
        counter += rec( 1, 0, i);
    }
    cout << counter << endl;
}