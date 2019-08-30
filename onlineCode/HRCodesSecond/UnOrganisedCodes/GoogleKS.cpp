//
// Created by kedar on 28/7/19.
// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000051061/0000000000161427

#include <bits/stdc++.h>


#include <vector>
using namespace std;

void solve(){
    int N, G, M;

    cin >> N >> G >> M;

    vector< pair<int, int>> arr;

    for(int i=0 ; i < G ; i++ ){
        int temp1, orient;
        char temp2;
        cin >> temp1 >> temp2;
        if(temp2 == 'A')
            orient = -1;
        else
            orient = 1;
        arr.push_back( make_pair(temp1, orient));

    }

    for(int i=0 ; i < M ; i++ ){
        for(int j=0 ; j < G ; j++ ){

            arr[j].first += arr[j].second;
            if(arr[j].first == 0)
                arr[j].first = 5;
            if(arr[j].first == 6)
                arr[j].first = 1;
            cout << arr[j].first << " ";
        }
        cout << endl;
    }
}

int main(){

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}