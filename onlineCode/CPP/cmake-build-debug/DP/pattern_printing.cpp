#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int N = 2*n-1;
    int arr[N][N];

    for (int k = 0; k < N; ++k){
        for (int i = 0; i < N; ++i){
            arr[k][i]  = -1;
        }
    }
    int counter=0;
    int ii=0, jj=0;
    for (int k = n; k > 0; --k) {

            int j = ii;
            int l = jj;
            while (l < N && arr[j][l] == -1  ) {
                arr[j][l] = k;
                l++;
            }
            l--;
            j++;
            while( j < N && arr[j][l] == -1 && arr[j][l] != n ){
                arr[j][l] = k;
                j++;
            }


            j = ii+1;
            l = jj;
            while( j < N && arr[j][l] == -1 && arr[j][l] != n ){
                arr[j][l] = k;
                j++;
            }
            j--;
            l++;
            while( j < N && arr[j][l] == -1 && arr[j][l] != n ){
                arr[j][l] = k;
                l++;
            }
        ii++; jj++;
    }


    for (int k = 0; k < N; ++k){
        for (int i = 0; i < N; ++i){
            cout << arr[k][i] << "\t"  ;
        }
        cout << endl;
    }

    string a ;
    a.length()
//    cout << counter << endl;

    return 0;
}
