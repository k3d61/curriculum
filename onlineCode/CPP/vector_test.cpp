#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <iostream>
#include <deque>

using namespace std;

void getAttr(vector<string> input, string find){
    int len = input.size();

    stringstream ss(find);
    string tag;
    char ch;
    ss >> tag;
    cout << "tag=" << tag << endl;
}

void printinput(vector<string> input){
    for (int i=0; i<input.size();i++){
        cout << "input=" << input[i] << endl;
    }
}

int vec(){

    vector<int> input;
    int n,q;
    cin >> n;
    for(int j=0; j<n;j++ ){
        int no;
        cin >> no;
        cout <<endl << "j=" << j << ":"<< no;
        input.push_back(no);
        //  mapper.insert(j,no);
    }
    cin >> q;
    for(int j=0; j<q;j++ ){
        int no;
        cin >> no;
        int pos = find(input.begin(), input.end(), no) - input.begin() +1;
        if (pos <= input.size())
            cout <<"Yes "<< find(input.begin(), input.end(), no) - input.begin() +1<< endl;
        else
            for(auto i=input.begin() ; i< input.end(); i++) {
                if(*i > no) {
                    cout << "No " << i - input.begin() +1<< endl;
                    break;
                }
            }

    }

    return 0;


    /* int N,Q;
     string str;
     getline(cin, str);
     stringstream ssinput(str);
     ssinput >> N >> Q;

     for(int i= 0 ;i<N ;i++ ){
         string str;
         getline(cin, str);

         input.push_back(str);
     }
     printinput(input);

     for(int i=0; i<Q ;i++ ){
         string str;
         getline(cin, str);
         getAttr(input,str);
     }*/
}


int setTest(){
    int N;
    cin >> N;
    set<int> s;

    for(int i=0; i<N ;i++ ){
        int type ,no;
        cin >> type >> no;
        //cout << "input= " << type << ":" << no << endl;
        if(type == 1)
            s.insert(no);
        if(type == 2) {
            //auto index = s.find(no);
            s.erase(no);
        }
        if (type == 3) {
            auto index = s.find(no);
            if (index != s.end()) {
                cout << "Yes" << endl;
            } else
                cout << "No" << endl;
        }

    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    unordered_map<int,int> umap;
    for (int i = 0 ; i < n ; i++ ){
        int no = ar[i];
        //cout << "no=" << ar[i] << endl;

        auto index = umap.find(no);
        if(index != umap.end()){ // element exits
            int val = index->second;
            index->second = val+1;
//            cout << "val=" << val+1 ;
        }
        else { // insert new ele
            umap.insert({no,1});
        }
    }
    int count = 0;
    for(auto& x: umap){
        //cout << x.first << ": " << x.second << std::endl;
        count = count + x.second/2;
    }
    cout << count << endl;


}

int mapTest(){
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = sockMerchant(n, ar);

    fout << result << "\n";

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



void printKMax(int arr[], int n, int k){
    //Write your code here
  /*  deque<int> q;
    for(int i=0;i<k;i++){
        q.push_back(arr[i]);
    }
    for(int i=k; i<=n ; i++){
        int max = 0;
        for(auto a: q){
            if(max < a)
                max = a;
        }
        cout << max << " ";

        q.pop_front();
        q.push_back(arr[i]);
    }
    cout << endl;
  */  //Write your code here
    set<int> s;
    for(int i=0;i<k;i++){
        s.insert(arr[i]);
    }
    auto max = s.end();
    //printer(s);

    cout << *(--max) << " ";
    for(int i=k; i<n ; i++){
        int last_index = i-k;
        s.erase(arr[last_index]);
        s.insert(arr[i]);
        auto max = s.end();

        //printer(s);
        cout << *(--max) << " ";

    }
    cout << endl;


}


int DQtest(){

    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++) {
            cin >> arr[i];
            //cout << "i=" << i << ":"<<arr[i] << endl;
        }
        printKMax(arr, n, k);
        t--;
    }


    return 0;
}

void umapTest(){
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int Q;
    cin >> Q;
    unordered_map<string, int> mapper;
    for(int i=0 ; i<Q ; i++){
        int type,y;
        string x;
        cin >> type >> x;
        if(type == 1)
            cin >> y;
        cout << x << endl;
        auto iterator = mapper.find(x);
        if(iterator == mapper.end() && type == 1){
            mapper.insert({x,y});
        }
        if(iterator != mapper.end() && type == 1){
            iterator->second = iterator->second + y;
        }
        if(iterator != mapper.end() && type == 2){
            mapper.erase(x);
        }
        if(iterator != mapper.end() && type == 3){
            cout << iterator->second << endl;
        }

    }

}
void two_dvec(){
        // Initializing 2D vector "vect" with
        // values
        vector<vector<int> > A{ { 1, 2, 3 },
                                   { 4, 5, 6 },
                                   { 7, 8, 9 } };

        // Displaying the 2D vector
        /*for (int i = 0; i < vect.size(); i++) {
            for (int j = 0; j < vect[i].size(); j++)
                cout << vect[i][j] << " ";
            cout << endl;
        }
*/

        for(int i =0 ; i < A.size()  ; i++ ){
           for(int j=0 ; j < A[i].size() ; j++){
             cout << A[i][j]<< " ";
        }
        }
}
int main() {
    two_dvec();
    //    umapTest();

   // DQtest();
 //   vec();
    //mapTest();
//    setTest();
    return 0;
}
