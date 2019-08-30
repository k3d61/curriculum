#include <bits/stdc++.h>

using namespace std;

// Complete the counterGame function below.
long long power(int n){
    int i=1;
    long long mul = 1;
    while( i< n){
        mul *= 2;
        i++;
    }
    return mul;
}

int counterGame(long long n, int term) {

    if (n==1)
        return term;
    if(ceil(log2(n)) != floor(log2(n))){
        long long pow = power(log2(n));
        cout << pow <<" " << term << endl;
        if ((n-pow) == 1)
            return term;
        return counterGame(n-pow, term==1?0:1);
    }
    if(ceil(log2(n)) == floor(log2(n))){
        cout << n/2 <<" " << term << endl;
        if (n/2==1)
            return term;
        return counterGame(n/2, term==1?0:1);
    }

    return term;

}
long sumXor(long n) {
    long long counter = 0;
    for(long long i=0 ; i<=n ;i++){
        long long xxor = bitset<50>(n^i).to_ullong();
        if(i+n == xxor){
            counter++;
        }
        //cout << counter << endl;
    }
    return counter;
}

int main()
{

    cout <<"sumXor=" <<sumXor(1099511627776) << endl;
    cout << bitset<11>(5^10).to_string() << endl;
    string str = bitset<11>(5^6).to_string();
    int t;
    long long con = bitset<64>(str).to_ullong();
    cout << con << endl;

    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = counterGame(n,1);
        if(result == 0){
            cout << "Richard" << "\n";
        }
        else
            cout << "Louise" << "\n";
        //fout << result << "\n";
    }

//    fout.close();

    return 0;
}
