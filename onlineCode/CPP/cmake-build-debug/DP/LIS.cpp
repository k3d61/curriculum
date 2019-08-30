//
// Created by kedar on 1/6/19.
// longest increasing subsequence
//

#include <vector>
#include <bits/stdc++.h>

using namespace std;

int indexm = 0;

long maximum(long one, long two){
    return one > two ? one : two;
}
long lis(int *arr, int length, int prevMax){

    if( *arr == -1)
        return length;
    cout << "[Debug] "<< indexm++ << " " << *arr << " : " << length << " : " << prevMax << endl;
    long len =0;
    if( *arr > prevMax ){
        cout << "\tinc" << endl;
        len = maximum(lis(arr+1, 1+length , *arr ),
                lis(arr+1, length , *arr));
    }
    if( *arr <= prevMax ){
        cout << "\t\tdec" << endl;
        len = maximum(lis(arr+1, 1 , *arr ),
                      lis(arr+1, length , prevMax));
    }

    return len;


}

int main(){
    int ar[] = {2,4,3,7,4,5,-1};
            //{ 10, 22, 9, 33, 21, 50, 41, 60, -1 };
    vector<int> arr;

    for (int i=0 ; i<8 ; i++){
        arr.push_back( ar[i] );
    }

    cout << lis(ar, 0, 0 ) << endl;
    return 0;
}
