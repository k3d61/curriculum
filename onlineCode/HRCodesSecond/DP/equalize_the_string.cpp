#include <bits/stdc++.h>
// https://www.hackerrank.com/contests/coding-test-3-slot-1/challenges/equalize-the-strings

using namespace std;

int dpi( int i ){
	return i+1;
}

int lis(string a, string b){
	int lena = a.length();
	int lenb = b.length();

	// int dp[lena+1][lenb+1] = {{0}};
	vector<int> row(lenb+1, 0);
	vector<vector<int>>  dp(lena+1, row);

	for (int i = 0; i < lena+1; ++i)
	{
		for (int j = 0; j < lenb+1; ++j)
		{
			cout << dp[i][j] << "\t";
 		}
 		cout << endl;
	}

	for (int i = 1; i <= lena; ++i)
	{
		for (int j = 1; j <= lenb; ++j)
		{
			if( a[i-1] == b[j-1] ){
				dp[ i ][ j ] =  dp[ i-1 ][ j-1 ];
			}
			else
				dp[i][j] = 1+min( dp[ i ][ j-1 ], dp[ i-1 ][ j ] );
		}
	}

	for (int i = 0; i < lena+1; ++i)
	{
		for (int j = 0; j < lenb+1; ++j)
		{
			cout << dp[i][j] << "\t";
 		}
 		cout << endl;
	}

	return /*(max(lena, lenb) -*/ dp[lena][lenb];
}

int main(){

	string a, b;
	cin >> a >> b;

	// cout << "a = " << a << endl << "b = " << b << endl;

	cout << lis(a, b) << endl;
	return 0;
}