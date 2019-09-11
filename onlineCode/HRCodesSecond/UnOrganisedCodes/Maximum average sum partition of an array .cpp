//
// Created by kedar on 4/9/19.
// https://www.geeksforgeeks.org/maximum-average-sum-partition-array/

#include <bits/stdc++.h>

using namespace std;

#include <vector>
#include <set>

/*
int iterativeSolution(){

    int k, n;
    cin >>  n>> k;

    vector<int> input;
    for(int i=0 ; i < n ;i++){
        int t;
        cin >> t;
        input.push_back(t);
    }
    sort(input.begin(), input.end());

    vector<int> sum(k, 0) ;
    vector<int> size(k, 0);

    for(int i = n-1 ; i > -1 ;i--){
        int index = 0;
        float diff= 1e5;

//        cout << input[i] << endl;
        for(int j = 0 ; j < k ; j++){


            float old =0;
            if(size[j] != 0) old = sum[ j ] / (size[j]);
            else             old = 0;

            float newdiff = (sum[ j ] + input[i])/ (size[j]+1);
//            cout << "old = " << old <<  " new = " << newdiff << " old-new = " << old-newdiff << " diff = " << diff << "\n";
            if( (old - newdiff) < diff ) {
                diff = old-newdiff;
                index = j;

            }
        }

        sum[ index ] += input[ i ];
        size[ index ] += 1;
//        cout << "adding " << input[i] << " to set " << index << " sum = " << sum[index]  << endl;

    }
    float sumk = 0;
    for(int i = 0 ; i < k  ; i++ ){
//        cout << i << " -- " << sum[i] << " " << size[i] << endl;
        if(size[i] != 0)
            sumk += ( sum[i]/size[i] );
    }
    cout << sumk << endl;
    return 0;

}*/


vector<int> input;

float recur(int prev, int current, int k){

    float avgSum = 0.0;
    //finish at current, start new from next element
    for (int i = prev; i < current; ++i) {
        
    }

    // not finish at current

    return 0.0;
}

int main(){

    int k, n;
    cin >>  n>> k;

    for(int i=0 ; i < n ;i++){
        int t;
        cin >> t;
        input.push_back(t);
    }

    cout << recur(-1, 0, 3);

    return 0;
}

/*

5 3
9 1 2 3 9

 */
