//
// Created by kedar on 25/8/19.
//  https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edb/0000000000170721

#include<bits/stdc++.h>
using namespace std;

//#define flag 1
#define toPrint 1

#ifdef flag
#define pout(x) cout << x
#else
#define pout(x)
#endif

int find(int *arr, int i){
    while(arr[i] != i ) i = arr[i];

//    pout( i << " = " << arr[i] << endl);

    return i;
}

void printer(int *arr,int n){

    for(int i=1 ; i < n+1 ; i++){
        pout ( arr[i] << "\t");
    }
    pout (endl);
    for(int i=1 ; i < n+1 ; i++){
        pout ( i  << "\t");
    }
    pout(endl);

}

void weighted_union(int Arr[ ],int size[ ],int A,int B)
{
    int root_A = find(Arr, A);
    int root_B = find(Arr, B);
    if(size[root_A] < size[root_B ]){
        Arr[ root_A ] = Arr[root_B];
        size[root_B] += size[root_A];
    }
    else
    {
        Arr[ root_B ] = Arr[root_A];
        size[root_A] += size[root_B];
    }

}
int solve(){
    int n, m;
    cin >> n >> m;

    int size[n+1];
    int arr[n+1];
    for(int i=1 ; i < n+1 ; i++){
        arr[i] = i;
        size[ i ] = 1;
    }

    /*for(int i=0 ; i < m ; i++){
        int a , b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }*/
    for(int i=0 ; i < m ; i++){
        int a , b;
        cin >> a >> b;
        weighted_union(arr, size, a, b);
//        arr[ find(arr, a) ] = arr[ find(arr, b) ];
    }

    printer(arr, n);

    int counter = 0;
    for(int i=1 ; i < n+1 ; i++){
        if( arr[i] == i ) counter++;
    }
    pout(endl << "connect comp. = " << counter << endl) ;

    int blackEdges = (n-1)-(counter-1) ;
    int whiteEdges = (n-1)-blackEdges;
    pout(endl << "black dges = " << blackEdges << ", white = " << whiteEdges << endl) ;


    return blackEdges + whiteEdges*2;

}
int main(){

    int t;
    cin >> t;
    int i=1;
    while( i <= t) {
        int ret = solve();
        cout << "Case #" << i << ": " << ret << endl;

        i++;
    }



    return 0;
}

/*

1
4 3
1 2
2 4
4 1

1
6 5
1 2
2 5
1 5
3 6
1 4


2
2 1
1 2
3 1
2 3


*/
