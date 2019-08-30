//
// Created by kedar on 1/7/19.
//

#include <bits/stdc++.h>

using namespace std;

bool toPrint = false;
#define pout if(toPrint) cout


string organizingContainers(vector<vector<int>> container) {

    vector<int> row(container.size());
    vector<int> col(container.size());

    pout << endl;
    for (int i = 0; i < container.size(); i++) {

        for (int j = 0; j < container[i].size(); j++) {
            pout << container[i][j] << "\t";
            col[j] += container[i][j];
            row[i] += container[i][j];
        }

        pout << endl;
    }
    pout << "row = ";
    for (int i = 0; i < container.size(); i++) {
        pout << row[i] << "\t";
    }
    pout <<endl << "col = ";
    for (int i = 0; i < container.size(); i++) {
        pout << col[i] << "\t";
    }
    sort( row.begin(), row.end() );
    sort( col.begin(), col.end() );

    bool flag = false;
    for (int i = 0; i < container.size(); i++) {
        if( row[i] != col[i] )
            flag = true;
    }

    pout << endl;


    string ret = "Impossible";
    if ( !flag ){
        ret = "Possible";
        return ret;
    }
    return ret;
}

int main()
{

    int q;
    cin >> q;

    while(q--){
        int n;
        cin >> n;


        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);
            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }
        }

        string result = organizingContainers(container);

        cout << result << "\n";
    }

    return 0;
}

