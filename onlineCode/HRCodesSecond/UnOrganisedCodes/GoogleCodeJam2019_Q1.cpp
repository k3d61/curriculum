#include <iostream>
#include<bits/stdc++.h>
#include <string>

#include "header.h"

using namespace std;

int GoogleCodeJam_Q1() {

    int N, NoOfTest;
    int P;
    int skills[N];
    bool toPrint = true;

    cin >> NoOfTest;
    int counter =1;
    while (NoOfTest > 0){

        cin >> N;

        string str = to_string(N);

        int strLen = str.length();

//        for ( string::iterator it=str.begin(); it!=str.end(); ++it)
//            cout << *it;

        cout << str << endl;

        NoOfTest--;
    }
    return 0;
}

int main(){
    cout << "ola" ;
}