//
// Created by kedar on 21/6/19.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool toPrint = true;
#define pout if(toPrint) cout
int arr[1001][1001] = {0};
string A, B;

void printarr() {
    for (int j = 0; j <= B.length() ; j++) {
        for (int i = 0; i <= A.length() ; i++) {
            pout << arr[j][i] << "\t\t";
        }
        pout << endl;
    }
}
int distance(int a, int b){

    int minimum =0;
    for(int j=1 ; j <= B.length() ; j++ ){
        for(int i=1 ; i <= A.length() ; i++ ){

            int ifeq = 1;
            if( A[i-1] == B[j-1] )
                arr[j][i] = arr[j-1][i-1];
            else
                arr[j][i] =  min(arr[j][ i-1] +1,
                                  arr[j-1][ i] +1);




        }
    }
    printarr();
    return arr[b][a];
}

int main() {

    cin >> A >> B;
//    A= "xvat";
//    B= "a";
    for(int i=1 ; i <= A.length() ; i++ )
        arr[0][i] = i;
    for(int i=1 ; i <= B.length() ; i++ )
        arr[i][0] = i;


    cout << distance(A.length(), B.length()) << endl;



    return 0;
}
