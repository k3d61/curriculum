//
// Created by kedar on 10/6/19.
//

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool toPrint = true;
#define pout if(toPrint) cout
deque<int> que;
int level =1;
int leveler[1001];
bool partialVisit[1001];
// Complete the bfs function below.

vector<int> bfs(int n, int m, vector<int> edges[], int s, bool visited[]) {

    vector<int> l;
    pout << s << " ";
    visited[s] = true;

    for (int i = 0; i < edges[s].size() ; ++i) {
        if( ! visited[ edges[s][i] ] ){
            que.push_back(edges[s][i]);
            //pout <<">>>>" << s << ", " << leveler[s] << "++" << edges[s][i] << endl ;
            if( ! partialVisit[ edges[s][i] ] )
                leveler[ edges[s][i] ] = leveler[s]+1 ;
            partialVisit[ edges[s][i] ] = true;

        }
    }
    if( !que.empty() ){
        int poped = que[0];
        que.pop_front();
        if( ! visited[ poped ] ) {
            bfs(n, m, edges, poped, visited);
        }
    }

    return l;
}

void printGraph( vector<int> alg[], int n){
    pout << endl;
    for(int i = 1 ; i<n ;i++ ){
        pout << i << "-->" ;
        for(int j=0 ; j< alg[i].size() ; j++ ){
            pout << alg[i][j] << " ";
        }
        pout << endl;
    }

}

int main()
{

    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n ;
        int m ;
        cin >> n >> m;

        vector<int> edges[n+1];
        bool visited[n+1];

        for (int i = 1 ; i < n+1; i++)  {
            visited[i] = false;
            partialVisit[i] = false;
            leveler[i] = -1;
        }

        for (int i = 0; i < m; i++) {
                int first;
                int second;
                cin >> first >> second;
                edges[first].push_back(second);
                edges[second].push_back(first);
        }

        printGraph(edges, n+1);
        pout << endl;

        int s;
        cin >> s;
        leveler[s] =0;
        vector<int> result = bfs(n, m, edges, s, visited);

/*
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }
*/
    string str = "ass";
    str[0];
        pout << endl;

        for (int j = 1; j < n+1; ++j) {
            pout << "(" << j << "," ;
            if(j!=s && leveler[j] !=  -1 )
                cout << leveler[j] *6 << " " ;
            if( leveler[j] == -1 )
                cout << "-1" << " ";
            pout << ")" << endl;
        }
        cout << "\n";
    }
    return 0;
}

