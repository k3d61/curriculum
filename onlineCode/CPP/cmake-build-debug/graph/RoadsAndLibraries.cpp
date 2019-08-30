//
// Created by kedar on 7/6/19.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<string> split_string(string);

bool findv(vector<int> vector);

long onlyLibvalue(vector<vector<int>> vector);

long long DFSTravel(int k, vector<vector<int>> vector, bool *pBoolean);

bool findv(vector<int> vector, int first) {

    for(auto it = vector.begin() ; it != vector.end() ; it++){
        if( *it == first )
            return  true;

    }

    return false;
}

bool print = true;

void printVV( vector<vector<int>> vv){
    for(int i=0 ; i < vv.size() ;i++){
        for(int j = 0 ; j < vv[i].size() ; j++) {
            if(print) cout << vv[i][j] << " -  " ;
        }
        if(print) cout << endl;
    }

}
#define pout if(print) cout
// Complete the roadsAndLibraries function below.
long long  roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {

    if( c_lib < c_road )
        return n * c_lib;


    vector<vector<int>> vv;
    int inv= 1;

    vv.resize(vv.size()+1);

    vv[0].push_back(cities[0][0]);
    int connectedNodeCount = 1;

    for(int i=0 ; i < cities.size() ;i++){
        int first = cities[i][0];
        int second = cities[i][1];

        if(print) cout << endl << first << " :: " << second << endl;

       int l = 0;
        for( int l=0 ; l< inv ; l++) {
            vector<int> v = vv[l];
            pout << "first ret =" << findv(v, first) << " second ret=" << findv(v, second) << endl;
            bool isPresentFirst = findv(v, first);
            bool isPresentSecond = findv(v, second);

            if ( !isPresentFirst && !isPresentSecond ){
                vv.resize(vv.size()+1);
                if (print) cout << "adding vector" << endl;
                vv[inv].push_back(first);
                vv[inv].push_back(second);
                connectedNodeCount += 2;
                inv++;
            } else if ( isPresentFirst && isPresentSecond ){
                pout << "present" << endl;
            } else if ( isPresentFirst) {
                pout << "addind second" << endl;
                vv[l].push_back(second);
                connectedNodeCount++;
                //break;
            } else if ( isPresentSecond ) {
                pout << "addind first" << endl;
                vv[l].push_back(first);
                connectedNodeCount++;
            }

        }

    }
    pout << endl << "connected nodes= " << inv << endl;
    printVV(vv);
    int unConnectedNode = n-connectedNodeCount;
    pout << "unconnectred nodes = " << unConnectedNode << " vv.size() = " << vv.size() << endl;

    long sum = c_lib * (vv.size() + unConnectedNode);
    pout << "sum = " << sum << endl;

    for (int j = 0; j < vv.size() ; ++j) {
        pout << "vv(j).size() =" << vv[j].size()<< endl;
        sum += (vv[j].size()-1) * c_road;
    }

    return sum;
}


long long  roadsAndLibraries2(int n, int c_lib, int c_road, vector<vector<int>> cities) {

    if( c_lib < c_road )
        return n * c_lib;

    bool visited[n+1];

    vector<vector<int>> vv(n+1);

    for( long  i=0 ; i < cities.size() ; i++){
        int first = cities[i][0];
        int second = cities[i][1];
        vv[ first ].push_back( second );
        vv[ second ].push_back( first );

    }
    for( long  i=1 ; i < vv.size() ; i++){

        visited[i] = false;
        pout << i << "->" ;
        for (long  j = 0; j < vv[i].size(); ++j) {
            pout << vv[i][j] << " ";
        }
        pout << endl;
    }

    long connectedComponents = 0;
    long numberOfEdges = 0;
    for (long k = 1; k < vv.size(); ++k) {
        if( ! visited[k] ){
            long temp = DFSTravel( k, vv, visited );
            numberOfEdges += temp;

            pout << " = " << temp << endl;
            connectedComponents++;
        }
    }
    pout << "connectedComponents =" << connectedComponents << endl;
    pout << "numberOfEdges =" << numberOfEdges << endl;

    return (connectedComponents*c_lib) +(numberOfEdges*c_road);
}

long long DFSTravel(long long k, vector<vector<int>> vv, bool *visited) {


    visited[k] = true;
    pout << k;

    long long ret =0;
    for (long long i = 0 ; i < vv[k].size() ; ++i){
        //pout <<" " << k << "::" << vv[k][i] << endl;
        if( !visited[ vv[k][i] ])
            ret += 1+DFSTravel( vv[k][i], vv, visited);
    }
    return ret;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long long result = roadsAndLibraries2(n, c_lib, c_road, cities);

        cout << result << "\n";
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
