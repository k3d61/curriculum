//
// Created by kedar on 14/6/19.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 * Input :
 *      N M
 *      N - number of nodes
 *      M - num or of edges
 * */
vector<int> nodes;
vector<int> size;


int root(int A){

    while( nodes[A] != A ){
        A = nodes[A];
    }
    return A;
}
bool find(int A, int B){

    if (root(A) == root(B))
        return true;
    return false;
}

bool toPrint = true;
#define pout if(toPrint) cout

void printNodes(){
    pout << "root ";
    for (int i = 1; i < nodes.size(); ++i) {
        pout << nodes[i] << "\t" ;
    }
    pout << endl;
    pout << "node ";
    for (int i = 1; i < nodes.size(); ++i) {
        pout << i << "\t" ;
    }
    pout << endl;
}

#include <set>

int connectedComponents( int N){

    int firstNode = 1;
    int edgeCounter = 0;
    set<int> s;
    for (int i = 2; i < nodes.size(); ++i) {
        int rootOfi = root( i );
        if( root(firstNode) != rootOfi ) {
            auto it = s.find( rootOfi );
            if( it == s.end() ) {

                s.insert( rootOfi );
            }
        }

    }
    return s.size();
}
int main(){

    int N, M;
    cin >> N >> M;

    for (int j = 0; j < N+1 ; ++j) {
        nodes.push_back(j);
        size.push_back(1);
    }

    for (int i = 0; i < M; ++i) {
        int one, two;
        cin >> one >> two;
        nodes[ root(one) ] = root(two);
    }
    printNodes();
    cout <<"Connected component = " << connectedComponents(N) << endl;
}
