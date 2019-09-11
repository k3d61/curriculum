#include <bits/stdc++.h>
// https://www.hackerrank.com/contests/coding-test-8-slot-1/challenges/board-cutting/problem
using namespace std;

vector<string> split_string(string);


// Complete the boardCutting function below.
long long boardCutting(vector<long long> cost_y, vector<long long> cost_x) {
    long long n = cost_y.size()+1;
    long long m = cost_x.size()+1;
    long long modval = 1e9+7;
    // cout << "val = " << modval << endl;
    
    sort(cost_y.begin(), cost_y.end());
    sort(cost_x.begin(), cost_x.end());
    
    long long hcut = 1, vcut = 1;
    long long yindex = n-2, xindex = m-2;
    
    long long cost = 0;
    
    for(long long  i = 0 ; i < (m+n-2) ; i++ ){
        long long  toProcess;
    /*    cout << "cost_y[ yindex ] " << cost_y[ yindex ] <<
            "  <==>  cost_x[xindex] " << cost_x[xindex] << endl;
    */    
        if((cost_y[ yindex ] > cost_x[xindex]) && (yindex >= 0) ) {
            toProcess = cost_y[ yindex ];
            yindex--;
            hcut++;
            cost += vcut * toProcess;
            cost = cost % modval;
            // cout << "yprocess = " << toProcess << " cost = " << cost << endl << endl;
        }
        else if ((cost_y[ yindex ] <= cost_x[xindex]) && (xindex >= 0) ) {
            toProcess = cost_x[ xindex ];
            xindex--;
            vcut++;
            cost += hcut * toProcess;
            cost = cost % modval;
            // cout << "xprocess = " << toProcess << " cost = " << cost << endl << endl;
        }
        if( yindex < 0 && xindex >=0 ){
            toProcess = cost_x[ xindex ];
            xindex--;
            vcut++;
            cost += hcut * toProcess;
            cost = cost % modval;
            // cout << "xprocess = " << toProcess << " cost = " << cost << endl << endl;    
        }
        if( xindex < 0 && yindex >=0 ){
            toProcess = cost_y[ yindex ];
            yindex--;
            hcut++;
            cost += vcut * toProcess;
            cost = cost % modval;
            // cout << "yprocess = " << toProcess << " cost = " << cost << endl << endl;
        }
    }


    // cout << "cost = " << cost << endl << endl;
    return cost;
}

int main()   
{

    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {

        long long m, n;
        cin >> m >> n;  
        vector<long long> cost_y;
        for (int i = 0; i < m-1; i++) {
            long long temp;
            cin >> temp;
            cost_y.push_back(temp);
        }

        vector<long long> cost_x;

        for (int i = 0; i < n-1; i++) {
            long long temp;
            cin >> temp;
            cost_x.push_back(temp);
        }

        long long result = boardCutting(cost_y, cost_x);
        cout << result << endl;
    }

    return 0;
}

