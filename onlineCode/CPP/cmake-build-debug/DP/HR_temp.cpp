/*

#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

long long arr[10001][10001] ;

long long getCount(long long n, multiset<long> multi, long pc){

    //cout <<pc << "::" << n << endl;
    unsigned long counter = 0;
    if(n == 0){
        //cout << "got exact" << endl;
        return 1;
    }
    if( n < 0){
        return 0;
    }

    if(arr[n][pc] != -1){
        //cout << "->" << n << " " << arr[n][pc] << endl;
        return arr[n][pc];
    }

    for(auto &i : multi){
        //if(i >= pc)
        {
            counter += getCount(n-(i), multi, (i));
        }
    }

    arr[n][pc] = counter;
    return counter;
}


int main() {

    int t;
    cin >>t;
    while(t>0){
        int n=0;
        cin >> n;
        std::multiset<long> multi;
        multi.insert(1);
        multi.insert(2);


        for (int i=0 ; i<10000 ; i++)
            for(int j = 0; j < 10000; ++j)
                arr[i][j] = -1;


        int ret = getCount(n,multi,0);
        cout << ret;
        printf("%d", ret);
        t--;
    }
    return 0;
}

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;


int main() {

    char str[1000];
    int t=1;

    cin >> t;
    multiset<long> ms;
    unordered_map<long, long> um;
    vector<long> v;
    int T = t;
    while(t>0){

        long no;
        cin >> no;
        int len=0;
        ms.insert(no);
        um.insert({no, 0});
        v.push_back(no);
        t--;
    }

    t = T;
    auto it1 = ms.begin();
   /* while(t>0){
        cout << *it1 << " ";
        t--;
        it1++;
    }
*/
    t=T;
    int len=0;
    long i =1;
    auto it = ms.begin();

    auto vi = v.begin();

    while(t>0){
        std::string str;
        long no = *it;
        it++;
        while( len < no){
            str = std::to_string(i++);
            len += str.length();
            //cout <<">" << str << " : " << len << endl;
        }
        int index = no- (len-str.length()) -1 ;

        auto place = um.find(no);


        place->second = str[index]-48;
        //cout  <<place->first << " <> " <<  place->second  << "-->" << str[index] << endl;
        t--;
    }


    t = T;
//    auto temp = um.begin();
    vi = v.begin();
    while(t>0){
        auto place = um.find(*vi);
        //cout <<t <<", " <<place->first << " = " <<place->second<< endl;
        cout << place->second<< endl;
        t--;
        vi++;
    }
    return 0;
}
