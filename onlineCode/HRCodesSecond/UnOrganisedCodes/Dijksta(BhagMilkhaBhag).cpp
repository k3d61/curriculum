//
// Created by kedar on 1/9/19.
// https://www.hackerrank.com/contests/coding-test-7-full-test-1/challenges/bala-and-milkha



#include <cmath>


#include <cstdio>
#include <vector>
#include <set>
#include <unordered_map>

#include <iostream>
#include <algorithm>

using namespace std;

//#define flag 1
#define toPrint 0

#ifdef flag
#define pout(x) cout << x
#else
#define pout(x)
#endif



long long dijk(vector<vector<pair<long, long long>>> &al, long a, long b, int run){
    long n = al.size();

    bool visited[ n ]  ;
    long through[ n] ;
    long long weight[ n ] ;
    for (int k = 1; k < n ; ++k) {
        weight[k] = 1e5;
        through[k] = -1;
        visited[k] = false;
    }

    long next = a;
    weight[a] = 0;
    for(long i = 1 ; i < n ; i++){
        visited[next] = true;

        // weight updation phase
        for(long j = 0 ; j < al[next].size() ; j++){
            if( al[next][j].first == -1 )
                continue;

            long adjecent = al[next][j].first;
            long long adjecentWt = al[next][j].second;

            if( weight[ adjecent ] > weight[next] + adjecentWt ) {
                weight[ adjecent ] = weight[next] + adjecentWt;
                through[ adjecent ] = next;
            }
        }
        long min = 1e9;

        // choosing nearest node
        for(int i = 1 ; i < n  ; i++){
            if( toPrint ) cout << weight[i] << "\t.\t.\t.\t";
            if(weight[i] < min  && !visited[i] ){
                min = weight[i];
                next = i;
            }
        }

        if( toPrint ) {
            cout << endl;
            for (int i = 1; i < n; i++) {
                pout (through[i] << "\t.\t.\t.\t");
            }
            cout << endl;
            for (int i = 1; i < n; i++) {
                pout (visited[i] << "\t.\t.\t.\t");
            }
            cout << endl;
            cout << endl;
        }
    }

    if( run == 1 )
    while(b != a){
        long u, v;
        u = through[b];
        v = b;

        for (int i = 0; i < al[u].size(); ++i) {
            if( al[u][i].first == v  ){
                al[u][i].first = -1;
                al[u][i].second = -1;
            }

        }
        b = u;
    }
    if( run == 2 ){
        if( through[b] != -1 )
            return weight[b];
        else
            return -1;
    }

    return 0;

}

void printal( vector<vector<pair<long, long long>>> &al, int n){
    for(long i = 1; i < n+1 ; i++ ){
        cout << i;
        for(long j = 0 ; j < al[i].size() ; j++){
            cout  << " = " << al[i][j].first << ":" << al[i][j].second << " ";
        }
        cout << endl;


    }

}
int main() {

/*    unordered_map<int, unordered_map<int, int>> um;

    set< pair<int, int>> arr[2];
    arr[0].insert(make_pair(1, 2));
    arr[0].insert(make_pair(2, 2));
    arr[0].insert(make_pair(3, 2));
    arr[0].insert(make_pair(4, 2));
    arr[1].insert(make_pair(4, 2));
    arr[1].insert(make_pair(4, 2));
    arr[1].insert(make_pair(4, 6));

    arr[0].erase(make_pair(2,2));

    for (int i = 0; i < 2 ; ++i) {
        for(auto j : arr[i] ){
            cout << j.first << " : " << j.second << "\t"  ;
        }
        cout << endl;
    }*/

    long n,m;
    cin >> n >> m;
    long a, b;
    cin >> a >> b;

    vector<vector<pair<long, long long>>> al(n+1);
    for(long i =0 ; i < m ; i++ ){
        long u, v;
        long long w;
        cin >> u >> v >> w;
        al[u].push_back(make_pair(v, w));
    }

    if( toPrint ) {
        printal(al, n);
        cout << endl;
    }

    dijk(al, a, b, 1);

    if( toPrint ) {
        cout << "printing after 1st Dijk = :\n";
        printal(al, n);
        cout << endl;
    }
    cout << dijk(al, a, b, 2);


    return 0;
}

/*

7 10
1 7
4 3 4
2 5 3
5 7 8
5 3 1
1 2 5
7 5 6
7 4 7
6 2 9
3 2 0
7 3 2

 * */