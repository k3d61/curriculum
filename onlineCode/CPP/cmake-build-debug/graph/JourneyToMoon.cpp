//
// Created by kedar on 10/6/19.
//

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool toPrint = true;
#define pout if(toPrint) cout
vector<int> alg[100001];
bool visited[100001];


void printGraph(int n){
    for(int i = 0 ; i<n ;i++ ){
        pout << i << "-->" ;
        for(int j=0 ; j< alg[i].size() ; j++ ){
            pout << alg[i][j] << " ";
        }
        pout << endl;
    }

}

long DFS(int i){

    visited[i] = true;
    long temp =0;
    pout << i << " ";
    for(int j=0 ; j < alg[i].size() ; j++){
        if( !visited[ alg[i][j] ] ){
            temp += 1+DFS(alg[i][j]);
        }
    }
    return temp;
}

int main()
{

    int n,p;
    cin >>n >> p;

    for (int i = 0; i < p; i++) {

            int first ;
            int second ;
            cin >> first >> second;
            alg[first].push_back(second);
            alg[second].push_back(first);

    }

    printGraph(n);
    pout << endl;
    for(long i=0 ; i< n ; i++ ){
        visited[i] = false;
    }

    //now do DFS
    vector<long> counter;
    for(long i=0 ; i< n ; i++ ){
        long temp = 0;
        if( !visited[i] ){
            temp = DFS(i);
            //pout <<" = " << temp+1 << endl;
            counter.push_back( temp+1 );
        }
    }
    pout << "Got here" << endl;
    long N = counter.size();
    long long sum =0;
    for(long i=0 ; i< N ; i++ ) {
        for (long j = i+1; j < N; ++j) {
            sum += counter[i]*counter[j];
            pout << sum << endl;
        }
    }
    cout << sum;
    return 0;
}

