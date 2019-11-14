#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define MAX(a,b) a>b?a:b;
#define ll long long
vector<ll> inp;

int maxProduct(const int* A, int n) {

	cout << sin(6/3) << endl;	
	int min = 1;
	int max = 1;
	int ans = -1e5;
	for(int i=0 ; i < n ;i++){

		if(A[i] > 0){
			cout << "1 " << A[i] << endl;
			max *= A[i];
			min *= A[i];
			cout <<"\t" << max << " <> " << min << endl; 

		}
		else if( A[i] < 0){
			cout << "2 " << A[i] << endl;
			int temp = max;
			max = min * A[i];
			min = temp * A[i];
			cout <<"\t" << max << " <> " << min << endl; 

		}
		else if(A[i] == 0){
			cout << "3 " << A[i] << endl;
			max = 0;
			min = 1;
			cout <<"\t" << max << " <> " << min << endl; 
		}

		ans = MAX(max, ans);
		if(max == 0) max = 1;
	}
/*
8
1 -2 -3 0 5 6 -5 -3

*/
	cout << max << " " << min  << endl; 
	return ans;
}

int main(){

	int n;
	cin >> n;
	vector<int> inp(n);
	for(int i =0 ; i < n ; i++ ){
		int temp;
		cin >> temp;
		inp[i] = temp;
	}
	// inp.resize(n, 0);
	cout <<"ret = " <<maxProduct(inp.data(), n) << endl;

	return 0;
}