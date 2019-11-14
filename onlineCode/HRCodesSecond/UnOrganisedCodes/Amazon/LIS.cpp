
// https://www.geeksforgeeks.org/rank-elements-array/
// solution : https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
#include<bits/stdc++.h> 

using namespace std;
int lis_O_n(vector<int> &arr, int n){
    // O(n^2) approach

    std::vector<int> ret(n+1, 0);
    ret[n-1] = 1;
    for(int i = n-2 ; i >=0 ; i--){
        int j = i+1;
        int maxlen = -1;
        while( j < n ){ 
            if( arr[i ] < arr[j] && ret[j] > maxlen )
                maxlen = ret[j];
            j++;
        }
        if(maxlen == -1) ret[i]= 1;
        else ret[i] = maxlen+1;
        // if(i == n) ret[i] = 1;
        // else ret[i] = ret[j]+1;
        

    }

    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << "\t";
    }

    cout << endl;

    for(int i = 0 ; i < n ; i++){
        cout << ret[i] << "\t";
    }

    cout << endl;

    return ret[0];
}

int LIS_O_nlgn( std::vector<int> &arr, int n ){

    std::vector<int> v;

    for(int  i = 0; i < n ; i++){
        if(i == 0)
            v.push_back( arr[i] );
        else if(arr[i] > v[ v.size()-1 ])
            v.push_back( arr[i] );
        else{
            auto it = upper_bound( v.begin(), v.end(), arr[i] );
            *it = arr[i];
        }
    }
    return v.size();
}   
int main() 
{
    std::vector<int > arr= { 10, 22, 9, 100, 21, 50, 41, 60 }; 
    int n = arr.size(); 
    printf("Length of lis is %d \n", lis_O_n( arr, n )); 
    printf("Length of lis is %d \n", LIS_O_nlgn( arr, n )); 
      return 0; 
} 

