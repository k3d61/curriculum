//
// Created by kedar on 1/9/19.
// https://www.hackerrank.com/contests/coding--test-7-full-test-1/challenges/bala-and-milkha



#include <cmath>

#include <queue>
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


#define INTMAX 1e5

long long dijk(vector<vector<pair<long, long long>>> &al, long a){
    long n = al.size();

    bool visited[ n ]  ;
    long through[ n] ;
    long long weight[ n ] ;
    for (int k = 1; k < n ; ++k) {
        weight[k] = INTMAX;
        through[k] = -1;
        visited[k] = false;
    }

    int currentNode = a;
    weight[a] = 0;
    through[a] = a;

    typedef pair<int, int> pi; 
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    pq.push(make_pair( 0, a ));

    // priority_queue<pair<int, int>> pq;
    while(!pq.empty()){
        // visited[ currentNode ] = true;

        auto popped = pq.top();
        pq.pop();
        if(toPrint)cout << "popped = " << popped.second << endl;
        currentNode = popped.second;

        if(visited[currentNode]) continue;
        visited[currentNode] = true;
        weight[currentNode] = popped.first;

        // update neighbour of current
        for(auto p : al[currentNode]){
            int neighbour = p.first;
            if(toPrint)cout << ">> " << neighbour << " " <<  p.second << endl;
            if( visited[ neighbour ]) continue; 
            // visit if only not visited
                
            pq.push(make_pair( p.second + popped.first, neighbour ));

        }

        if(toPrint)
        for(int i = 1; i < n; i++){
            cout << i << "\t";
        }
        if(toPrint)cout << endl;
        if(toPrint)
        for(int i = 1; i < n; i++){
            cout << "--------";
        }
        if(toPrint)cout << endl;
        if(toPrint)
        for(int i = 1; i < n; i++){
            if(weight[i] == INTMAX) cout << -1 << "\t";
            else                    cout << weight[i] << "\t";
        }
        if(toPrint)cout << endl;
        if(toPrint)for(int i = 1; i < n; i++){
            cout << through[i] << "\t";
        }
        if(toPrint)cout << endl << endl ;

    }
    for(int i = 1; i < n; i++){
            if(i == a) continue;
            else if(weight[i] == INTMAX) cout << -1 << " ";
            else                    cout << weight[i] << " ";
        }
    cout << endl;
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

void solve(){
    long n,m;
    cin >> n >> m;
    
    vector<vector<pair<long, long long>>> al(n+1);
    for(long i =0 ; i < m ; i++ ){
        long u, v;
        long long w;
        cin >> u >> v >> w;
        al[u].push_back(make_pair(v, w));
        al[v].push_back(make_pair(u, w));
           
    }
    long a;
    cin >> a;

    if( toPrint ) {
        printal(al, n);
        cout << endl;
    }

    dijk(al, a);
    if(toPrint)cout << endl << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

}
int main() {
    // typedef pair<int, int> pi; 
    // priority_queue<pi, vector<pi>, greater<pi> > pq;
    // pq.push(make_pair( 20,100 ));
    // pq.push(make_pair( 10,90 ));
    // pq.push(make_pair( 40,80 ));
    // cout << "1. " << pq.top().first << endl;
    // pq.pop(); 
    // cout << "1. " << pq.top().first << endl;
    // pq.pop(); 
    // cout << "1. " << pq.top().first << endl;
    // pq.pop(); 
    int t; cin >> t;
    while(t--) solve();


    return 0;
}

/*

7 10
1 7
4 3 4
2 5 3
5 3 1
1 2 5
7 5 6
7 4 7
6 2 9
3 2 0
7 3 2

 * */