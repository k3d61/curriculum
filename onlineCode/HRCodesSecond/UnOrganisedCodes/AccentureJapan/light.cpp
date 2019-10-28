#include <bits/stdc++.h>
#include <string>

using namespace  std;

int solution(vector<int> &A) {

    bool light[A.size()+1] = {false};
    bool on[A.size()+1] = {false};
    
    long long count = 0;
    on[0] = 1;
    light[0] = 1;
    for(long long i = 0 ; i < A.size() ; i++){
        on[A[i]] = true;
        // cout << A[i] << endl;
        if( light[A[i]-1] == 1 ){
            // cout << "here" << endl;
            light[A[i]] = 1;
            count++;
            for(long long j = A[i];  j < A.size() && on[j] == 1 ; j++  ){
                light[j] = 1;
            }
        }
        // for(long long l =0; l < A.size() ; l++)
        //     cout << light[l] << " ";
        // cout << endl;
        // for(long long l =0; l < A.size() ; l++)
        //     cout << on[l] << " ";
        // cout << endl << endl;

    }   
    return count;
}

int main(){

    vector<int > A;
    A.push_back(2);
    A.push_back(1);
    A.push_back(3);
    A.push_back(5);
    A.push_back(4);
    cout << solution(A) << endl;
    // A.push_back();
    // A.push_back();
    // A.push_back();
    // A.push_back();
    return 0;
}