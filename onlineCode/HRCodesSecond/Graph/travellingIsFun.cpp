
//
// Created by kedar on 27/8/19.
// https://www.hackerrank.com/contests/hack-it-to-win-it-paypal/challenges/q4-traveling-is-fun/problem

#include <bits/stdc++.h>

using namespace std;

#define flag 1
#define toPrint 1


#ifdef flag
#define pout(x) cout << x
#elif
#define pout(x)
#endif

int find(int i, vector<int > &arr){
    while( arr[i] != i ) {
        i = arr[i];
    }
    return i;
}

void unionFind(vector<int> &arr , vector<int> &size, int a, int b){

    int roota = find( a, arr);
    int rootb = find( b, arr);


    if(size[ roota ] >= size[rootb]){
        arr[rootb] = roota;
        size[roota] += size[rootb];
    } else {
        arr[roota] = rootb;
        size[rootb ] += size[roota];
    }
}

void printArr(vector<int> &arr, int n){
    for (int k = 1; k < n+1 ; ++k) {
        pout( arr[k] << "\t");
    }
    pout(endl);
    for (int k = 1; k < n+1 ; ++k) {
        pout( k << "\t");
    }



    pout(endl);

}
int main(){

    int n, g;
    cin >> n >> g;
    int q;
    cin >> q;

//    vector<int> row(2, -1);
    vector<vector<int> > queries(q, vector<int>(2));

    vector<int> arr(n+1);
    for (int j = 1; j < n+1; ++j) arr[j] = j;

    vector<int> size(n+1, 1);

    vector<bool> visited(n, false);


    for (int l = g+1; l < n+1 ; ++l) {
        if( visited[l] == true ) continue;
        for (int i = 1; i*l < n+1 ; ++i) {
            visited[ i*l ] = true;
            unionFind(arr, size, l, l*i);
        }
    }
//    printArr(arr, n);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < q; ++j) {
            int temp;
            cin >> temp;
            queries[j][i] = temp;
        }
        if( i < 1 )
            cin >> q;
    }

    for (int j = 0; j < q; ++j) {
        if( find( queries[j][0], arr ) == find( queries[j][1], arr )){
            cout << "1\n";
        } else
            cout << "0\n";
    }


        return 0;
}

/*

6 1
4
1 2 4 6
4
3 3 3 4


     unionFind(arr, size, 1,4);
    unionFind(arr, size, 1,5);
    unionFind(arr, size, 1,3);
    unionFind(arr, size, 2,6);
    unionFind(arr, size, 3,6);

*/
