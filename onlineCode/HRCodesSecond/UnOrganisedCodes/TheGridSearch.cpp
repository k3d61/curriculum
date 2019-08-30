//
// Created by kedar on 10/7/19.
//

#include <bits/stdc++.h>
/*

1
10 10
7283455864
6731158619
8988242643
3830589324
2229505813
5633845374
6473530293
7053106601
0834282956
4607924137
3 4
9505
3845
3530


 -------------

1
4 6
123412
561212
123634
781288
2 2
12
34
 */
using namespace std;

vector<string> split_string(string);

bool toPrint = false;
#define pout if(toPrint) cout

bool patternMatch(int i, int j, vector<string> G,vector<string>  P){
    bool isMatch = true;
    int row = P.size();
    int col = P[0].size();

    pout << endl;
    for(int a = 0 ; a < row ; a++ ){

        for(int b = 0 ; b < col ; b++ ){
            pout << G[ (a+i) ][  (b+j) ] << " = " << P[ a ][ b ] << endl;
            if(     G[ (a+i) ][  (b+j) ] != P[ a ][ b ] )
                isMatch = false;
        }
    }
    return isMatch;
}

string gridSearch(vector<string> G, vector<string> P) {

    int row = G.size();
    int col = G[0].size();
    int p_row = P.size();
    int p_col = P[0].size();
    pout << endl;
    bool isMatched = false;
    for(int i = 0; i < row - p_row+1; i++){
        for(int j = 0; j < col - p_col+1; j++){

            if( patternMatch(i, j, G, P)){
                pout << "matched" << endl;
                isMatched = true;
                break;
            }

        }
        if (isMatched)
            break;
    }

    string ret = "NO";
    if(isMatched) {
        ret = "YES";
        return ret;
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string RC_temp;
        getline(cin, RC_temp);

        vector<string> RC = split_string(RC_temp);

        int R = stoi(RC[0]);

        int C = stoi(RC[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string rc_temp;
        getline(cin, rc_temp);

        vector<string> rc = split_string(rc_temp);

        int r = stoi(rc[0]);

        int c = stoi(rc[1]);

        vector<string> P(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            P[i] = P_item;
        }

        string result = gridSearch(G, P);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
