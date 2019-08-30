//
// Created by kedar on 14/7/19.
//

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int kcounter = 0;
int probab_at_node = 0;
int K = 0;

bool toPrint = true;
#define pout if(toPrint) cout

void dfsForFirst( int i, int prev, vector<vector<int>> al, bool *visited, unordered_map<int, int> guess) {

    visited[i] = true;
    pout << prev << " -> " << i  << endl ;

    if(prev != -1){
        auto it = guess.find( i );
        if( it != guess.end() ){
            if( i == it->first && ( prev == it->second ) ){
                pout << "it's match = " << it->first << " " << it->second << endl;
                probab_at_node++;
            }
        }

    }

    for(int j = 0 ; j < al[i].size() ;j++){

        if( !visited[ al[i][j] ] ){
            dfsForFirst( al[i][j], i, al , visited, guess);
        }
    }

}

void dfsForAll( int i, int prev, vector<vector<int>> al, bool *visited, unordered_map<int, int> guess, int *guess_counter) {

    visited[i] = true;
    pout << prev << " -> " << i << " )))" << endl  ;

    if( prev != -1) { // this should not be first node
        auto it = guess.find( prev );
        if( it != guess.end() ){
            pout << "here = " << it->first << " " << it->second << endl;

            if( (prev == it->first) &&
                ( i == it->second ) ){
                guess_counter[ i ] = guess_counter[prev] +1;
            }
            else
                guess_counter[ i ] = guess_counter[prev] -1;
        }
        else
            guess_counter[ i ] = guess_counter[prev];

        it = guess.find( i );
        if( it != guess.end() ){
            pout << "here = " << it->first << " " << it->second << endl;
            if( i == it->first && ( prev == it->second ) ){
                guess_counter[ i ] = guess_counter[prev] -1;
            }
        }

    }
    pout << "(((, guess_counter = " << guess_counter[i] << endl;
    if( guess_counter[i] >= K)
        kcounter++;

    for(int j = 0 ; j < al[i].size() ;j++){
        if( !visited[ al[i][j] ] ){
            dfsForAll( al[i][j], i, al , visited, guess, guess_counter);
        }
    }

}


string storyOfATree(int n, vector<vector<int>> edges, int k, vector<vector<int>> guesses) {

    K=k;

    unordered_map<int, int> guess;

    for(int i=0 ; i < guesses.size() ; i++ ){
//        pout << " ==" << guesses[i][1] << " " << guesses[i][0] ;
        guess.insert({ guesses[i][1], guesses[i][0] });
    }
    pout << endl;

    vector<vector<int>> al( n+1 );
    for(int i = 0 ; i < edges.size() ; i++){

        al[ edges[i][0] ].push_back(edges[i][1]);
        al[ edges[i][1] ].push_back(edges[i][0]);

    }

//    pout << "a list=" << endl;
//    for(int i = 1 ; i < n+1 ; i++){
//        pout << i << " = ";
//        for(int j = 0 ; j < al[i].size() ; j++ ){
//            pout << al[i][j] << " " ;
//        }
//        cout << endl;
//    }
//    pout << "guess=" << endl;
//    for(auto i = guess.begin() ; i != guess.end() ; i++ ){
//        pout <<  i->first <<" " << i->second << endl;
//    }
//    pout << endl;

    int guess_counter[n+1] = {0};
    probab_at_node = 0;
    kcounter = 0;
    {
        bool visited[n+1] = {0};
        visited[1] = true;
        dfsForFirst( 1, -1, al , visited, guess);
    }
    pout <<"probab_at_node = " << probab_at_node << endl;

    {
        bool visited[n+1] = {0};
        visited[1] = true;

        guess_counter[1] = probab_at_node;
        dfsForAll( 1, -1, al , visited, guess, guess_counter);
    }
    cout << endl;
    while(__gcd(kcounter, n) != 1){
        int gcd = __gcd(kcounter, n);
        kcounter /= gcd;
        n /= gcd;
    }

    string ret = "" + to_string(kcounter) + "/" + to_string(n) ;
    return ret;
}

int main()
{


    int q;
    cin >> q;


    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;


        vector<vector<int>> edges(n-1);

        for (int edges_row_itr = 0; edges_row_itr < n-1; edges_row_itr++) {
            edges[edges_row_itr].resize(2);

            for (int edges_column_itr = 0; edges_column_itr < 2; edges_column_itr++) {
                cin >> edges[edges_row_itr][edges_column_itr];
            }

        }

        int g;
        int k;
        cin >> g >> k;

        vector<vector<int>> guesses(g);
        for (int guesses_row_itr = 0; guesses_row_itr < g; guesses_row_itr++) {
            guesses[guesses_row_itr].resize(2);

            for (int guesses_column_itr = 0; guesses_column_itr < 2; guesses_column_itr++) {
                cin >> guesses[guesses_row_itr][guesses_column_itr];
            }

        }

        string result = storyOfATree(n, edges, k, guesses);

        cout << result << "\n";
    }


    return 0;
}
/*

1
4
1 2
1 3
3 4
2 2
1 2
3 4

1
6
1 2
2 3
2 4
4 5
5 6
3 2
1 2
1 4
5 6

 */
