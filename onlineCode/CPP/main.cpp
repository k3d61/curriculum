#include <iostream>
#include<bits/stdc++.h>
#include "header.h"
using namespace std;
int main() {

    // foo();

    return GoogleCodeJam_Q1();



}

int foo(){

    int N,NT;
    int P;
    int skills[N];
    bool toPrint = true;

    std::cin >> NT;
    int counter =1;
    while (NT>0){

        std::cin >> N;
        std::cin >> P;

        int i =0;
        while (i<N){
            std::cin >> skills[i++];
        }


        for (int i = 0 ; i < N ; i++) {
            if (toPrint)cout << skills[i] << " " ;
        }
        if (toPrint)cout << endl;


        int n = sizeof(skills)/sizeof(skills[0]);

        if (toPrint)cout << "Sorted = ";
        sort(skills, skills+n);
        for (int i = 0 ; i < N ; i++) {
            if (toPrint)cout << skills[i] << " " ;
        }
        if (toPrint)cout << endl;


        int minSum = 0;

        for (int i = 0; i < P ; ++i) {
            minSum += skills[P-1] - skills[i];
        }
        if (toPrint)cout << minSum ;

        for (int i = 1, j = i+P-1; j < N ; ++j,++i) {
            int sum2 = minSum + 2*skills[j] - 3*skills[j-1] + skills[i-1];
            if ( minSum > sum2 ){
                minSum = sum2;
            }
        }

        cout <<"Case #"<< counter++ <<": "<< minSum<< endl;

        if (toPrint)cout<<endl;

        NT--;
    }
    return 0;

}