//
// Created by kedar on 18/8/19.
// link on whatsapp, goldman sache VJTI, MinumumMeetingCost
/*

4 4
1 2 3 -11
4 -10 5 -5
6 7 8 9
-30 6 -10 4

3 3
1 2 3
4 -10 5
6 7 8



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

void printSumArr(int n, int m, vector<int> arr[]){
    for(int i=0 ; i < n ; i++){
        for(int j=0 ; j < m ; j++ ) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
int main(){

    int n, m;
    cin >> n >> m;
    vector<int> arr[n];
    vector<int> sumArr[n];
    long long mul;
    for(int i=0 ; i < n ; i++){
        for(int j=0 ; j < m ; j++ ){
            int temp;
            cin >> temp;
            arr[i].push_back(-1*temp);
            sumArr[i].push_back(0);

        }
    }
    if(toPrint) printSumArr(n, m, arr);
    pout( endl);
    // row processing, left -> right
    for(int i=0 ; i < n ; i++){
        long long tempSum = 0;
        for(int j=0 ; j < m ; j++ ){
//            cout << arr[i][j] <<  " ";
            if(tempSum+arr[i][j] <= 0){
                tempSum=0;
                sumArr[i][j] += arr[i][j];

            }
            else if(tempSum+arr[i][j] > 0){
                tempSum += arr[i][j];
                sumArr[i][j] += tempSum;
            }
        }
        cout << endl;
    }
    pout ("row left -> right"<< endl);
    if(toPrint) printSumArr(n, m, sumArr);

    // row processing, right -> left
    for(int i=0 ; i < n ; i++){
        long long tempSum = 0;
        for(int j = m-1 ; j >= 0 ; j-- ){
//            cout << arr[i][j] <<  " ";
            if(tempSum+arr[i][j] <= 0){
                tempSum=0;
                sumArr[i][j] += arr[i][j];

            }
            else if(tempSum+arr[i][j] > 0){
                tempSum += arr[i][j];
                sumArr[i][j] += tempSum;
            }
        }
        cout << endl;
    }
    pout ("row right to left" << endl );
    if(toPrint) printSumArr(n, m, sumArr);

    // column processing, top -> bottom
    for(int j = 0 ; j < m ; j++ ){
        long long tempSum = 0   ;
        for(int i=0 ; i < n ; i++){
            if(tempSum+arr[i][j] <= 0){
                tempSum=0;
                sumArr[i][j] += arr[i][j];

            }
            else if(tempSum+arr[i][j] > 0){
                tempSum += arr[i][j];
                sumArr[i][j] += tempSum;
            }
        }
        cout << endl;
    }
    pout ("column processing, top -> bottom" << endl);
    if(toPrint) printSumArr(n, m, sumArr);

// column processing, bottom -> top
    for(int j = 0 ; j < m ; j++ ){
        long long tempSum = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            if(tempSum+arr[i][j] <= 0){
                tempSum=0;
                sumArr[i][j] += arr[i][j];

            }
            else if(tempSum+arr[i][j] > 0){
                tempSum += arr[i][j];
                sumArr[i][j] += tempSum;
            }


        }
        cout << endl;
    }
    pout( "column processing, bottom -> top" << endl);
    if(toPrint) printSumArr(n, m, sumArr);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++ ){
            sumArr[i][j] -=  3*arr[i][j];
        }
        cout << endl;
    }
    pout( "arrSum[i][j] - 3*arr[i][j]" << endl);
    if(toPrint) printSumArr(n, m, sumArr);

    return 0;
}


