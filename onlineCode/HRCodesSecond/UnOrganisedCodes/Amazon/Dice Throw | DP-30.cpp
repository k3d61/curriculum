
// C++ Program to print Bottom View of Binary Tree 
#include<bits/stdc++.h> 
using namespace std; 
  
int M;

int recur( int n, int x){
    static vector<vector<int>> dp(n+1, vector<int> (x+1, -1));


    if (x < 0 || n < 0) return 0;
    if( x == 0 && n == 0 ) return 1;
    // if( dp[n][x] != -1 ) return dp[n][x];
    // if( x == 0 && n != 0 ) return 0;
    int sum = 0;
    for(int i=1 ; i<= M ; i++){
        sum += recur(n-1, x-i);
    }
    dp[n][x] = sum;
    return sum;
}
// Driver Code 
int main() 
{ 
    std::vector<char> v;
    int m,n,x;

    cin >> m >> n >> x;
    M = m;
    cout << recur( n, x) << endl;
    return 0; 
} 



