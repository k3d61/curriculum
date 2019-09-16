//https://www.hackerrank.com/challenges/synchronous-shopping/problem?h_r=next-challenge&h_v=zen&isFullScreen=true


#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <bitset>
// #include <pair>
using namespace std;

vector<vector<int>> centers;

/*
5 5 5
1 1
1 2
1 3
1 4
1 5
1 2 10
1 3 10
2 4 10
3 5 10
4 5 10

*/

int N ;
vector<pair<bitset<11>, int>> paths;

void DFS(vector<vector<pair<int, int>>> &roads, bitset<11> fish, bool *visited, int i,
        int sum){
    visited[i] = true;

    cout << "visit = " << i << endl;

    bitset<11> tempBitset(fish.to_string() );
    for( int j = 0 ; j < centers[i].size() ; j++ ){
        // cout << centers[i][j] << " ";
        int toProcess = centers[i][j];
       tempBitset.flip( toProcess );
    }

    if( i == N ){
        cout << "returning from here = " << tempBitset << " sum = " << sum << endl;
        paths.push_back( make_pair(tempBitset, sum)/*.to_string()*/ );
        return ;
    }

    // cout << tempBitset << endl;
    
    for(int j = 0 ; j < roads[i].size() ; j++){
        int toProcess = roads[i][j].first;
        if( visited[ toProcess ] == false || toProcess == N)
            DFS( roads, tempBitset, visited, toProcess, sum+roads[i][j].second ); 
    }

}

int shop(int n, int k, vector<vector<int>> &centers, vector<vector<pair<int, int>>> &roads) {
    
    bitset<11> fish("00000000000");
    bool visited[n+1] = {false};
    DFS( roads, fish, visited, 1 , 0);

    cout << endl;
    for (int i = 0; i < paths.size(); ++i)
    {

        for(int j = i+1; j < paths.size() ; j++ ){
            bitset<11> a = paths[i].first, b = paths[j].first;
            a |= b;
            cout <<" --> " <<  a <<" count = " << a.count()
                 << " asum = "<< paths[i].second
                 << " asum = "<< paths[j].second<< endl;
        }
    }
    return 0;
}

int main()
{

    
    int n, m, k;
    cin >>n >>m >> k;
    N = n;

    centers.clear();
    centers.resize(n+1);

    for (int i = 1; i < n+1; i++) {
        int temp;
        cin >> temp;
        for(int j = 0 ; j < temp ; j++){
            int fish;
            cin >> fish;
            centers[i].push_back(fish);
        }
    }

    vector<vector<pair<int, int>>> roads(n+1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        roads[u].push_back( make_pair(v, w) );
        roads[v].push_back( make_pair(u, w) );
    }


    // for(int i = 0 ; i < roads.size() ; i++ ){
    //     cout << i << " --> ";
    //     for(int j = 0 ; j < roads[i].size() ; j++ ){
    //         cout << roads[i][j].first << " ";
    //     }
    //     cout << endl;
    // }
    int res = shop(n, k, centers, roads);

   cout <<"RES = " << res << "\n";


    return 0;
}

 
