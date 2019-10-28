#include <bits/stdc++.h>

using namespace std;

/*

5
10 2 -10 5 20

*/
long INF = -1e5;

long solve(vector<long> &input){

	// long dp[input.size()] ;
	// for(int i = 1 ; i < input.size() ; i++) {
	// 	dp[i] = INF;
	// }
	long n = input.size();

	for (int i = n-1; i > 0; --i) {
		
		long temp = 0;

		if( (i+1) < n && (i+2) < n)
			temp = max( input[i+1], input[i+2] );
		else if((i+1) < n)
			temp = input[i+1];

		input[i] += temp;

		cout << i << " " << input[i] << endl;

	}


	return 0;
}

int main(){


	int n;
	cin >> n;
	vector<long> input(n+1);
	for(int i=1 ; i <= n ; i++){
		cin >> input[i];
	}

	solve(input);
	return 0;
}