#include <bits/stdc++.h>

using namespace std;

bool toPrint = true;
#define pout if(toPrint) cout

vector<string> split_string(string);

long allNegValue;

bool isAllNegative(vector<int> arr){

    bool isNeg = false;
    allNegValue = arr[0];

    for(int i = 1 ; i < arr.size() ; i++ ){
        if( arr[i] >= 0 )
            isNeg = true;
        if( allNegValue < arr[i] )
            allNegValue = arr[i];
        //pout << "-->" << allNegValue << endl;
    }
    return isNeg;
}


vector<long long> ret(2);

vector<long long> maxSubarray(vector<int> arr) {



    if( ! isAllNegative(arr) ){
        vector<long long> l;
        //pout << "==" << allNegValue << endl;
        ret[0] = allNegValue;
        ret[1] = allNegValue;
        return l;
    }

    long long maxSum = 0;
    long long currentMax = maxSum;
    long long absoluteSum = 0;

    for(int i = 0 ; i < arr.size() ; i++ ){

        absoluteSum += arr[i] > 0 ? arr[i] : 0;

        currentMax = currentMax + arr[i] > 0 ? currentMax + arr[i] : 0;
        if( currentMax > maxSum )
            maxSum = currentMax;
        pout << arr[i] <<  " : " << currentMax << " : " << maxSum << endl;
    }
    ret[0] = maxSum;
    ret[1] = absoluteSum;
    return ret;

}

int main()
{
    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (long i = 0; i < n; i++) {

            int arr_item ;
            cin >> arr_item;
            arr[i] = arr_item;
        }

        vector<long long> result = maxSubarray(arr);

        for (int i = 0; i < ret.size(); i++) {
            cout << ret[i] << " ";
        }
        cout << endl;
    }


    return 0;
}

