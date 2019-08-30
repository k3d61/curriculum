//
// Created by kedar on 22/7/19.
// https://www.hackerrank.com/contests/test2-m/challenges/best-divisor
//

#include <bits/stdc++.h>
#include <string>

using namespace std;

bool toPrint = true;
#define pout if(toPrint) cout

long digitSum(long a){
    string str = to_string(a);
    long sum = 0;
    for(int i = 0 ; i < str.length() ; i++){
        sum += str[i]-'0';
    }

    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector< pair<long, long> > vect;
    for(int i = 1 ; i <= n/2 ; i++ ){
        if(n%i == 0){

            long sum = digitSum(i);
            pout << i << " = " << sum << endl;
            vect.push_back( make_pair( sum, i ));
        }
    }
    sort( vect.begin(), vect.end() );
    long max  = vect[vect.size()-1].first;
    long ret = vect[vect.size()-1].second;


    pout << "size = "<< vect.size() << " max = " << max << endl << endl;

    for(int i = vect.size()-1 ; i >=0 && max == vect[i].first ; i-- ){
        if( vect[i].second < ret ){
            ret = vect[i].second;
        }
        pout << i << " <--> " << vect[i].first << " = " << vect[i].second << endl;
    }
    cout << ret << endl;
    return 0;
}


