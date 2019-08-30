/*
#include <bits/stdc++.h>
#include <set>
#include <map>
using namespace std;

vector<string> split_string(string);
map<long, unsigned long> mapper;
long long arr[251][251] ;

long long getCount(long long n, multiset<long> multi, long pc){

    cout <<pc << "::" << n << endl;
    unsigned long counter = 0;
    if(n == 0){
        cout << "got exact" << endl;
        return 1;
    }
    if( n < 0){
        return 0;
    }

    if(arr[n][pc] != -1){
        cout << "->" << n << " " << arr[n][pc] << endl;
        return arr[n][pc];
    }

    for(auto &i : multi){
        if(i >= pc){
            counter += getCount(n-(i), multi, (i));
        }
    }

   arr[n][pc] = counter;
    return counter;
}

// Complete the getWays function below.
long long getWays(long n, vector<long> c) {
    std::multiset<long> multi;
    for(int i = 0 ; i < c.size() ; i++){
        multi.insert(c[i]);
    }
    for(auto i = multi.begin() ; i != multi.end() ; i++) {
        cout << "-"<< *i ;
    }
    for (int i=0 ; i<251 ; i++)
        for(int j = 0; j < 251; ++j)
            arr[i][j] = -1;

    cout <<  endl;
    long long ret = getCount(n,multi,0);
    //cout << ret;
    return ret;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<long> c(m);

    for (int i = 0; i < m; i++) {
        long c_item = stol(c_temp[i]);

        c[i] = c_item;
    }

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    long ways = getWays(n, c);
    cout << ways;
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
*/
