//https://www.codechef.com/SEPT19B/problems/CHEFINSQ
// TAG : combinatories 
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int nCr(int n, int r){

	if ( r > n) return 0;
	if ( r*2 > n ) r = n-r;
	if ( r == 0 ) return 1 ;

	int sum = n;
	for (int i = 2; i <= r; ++i)
	{
		sum *= ( n-i+1);
		sum /= i;
	}
	return sum;

}
int solve(vector<int> &input, int k){

	sort(input.begin(), input.end());

	int count = 0;
	int place_count = 0; 
	int checkRepeat = input[k-1];
	for (int i = k; i < input.size() && input[i] == checkRepeat; ++i)
	{
			count++;
	}
	for (int i = k-1; i > 0 && input[i] == checkRepeat; --i)
	{
		place_count++;
	}
	int numbers = count + place_count;

	
	int ncr = nCr(numbers, place_count);

	// cout << "multi = " << multi << endl;
	return ncr;
}

/*

1
5 3
1 2 2 2 2

*/
void CIS(){
	int n , k ;
	cin >> n >> k ;
	vector<int> input(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];

	}

	cout << solve(input, k);

}

int main(){

	int t ;
	cin >> t;
	while(t--) CIS();
	return 0;
}