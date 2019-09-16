//https://www.codechef.com/SEPT19B/problems/CHEFINSQ

#include <bits/stdc++.h>
#include <vector>

using namespace std;

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

	
	int minr = place_count > numbers-place_count ? numbers-place_count : place_count;
	float multi = 1.0;
	// cout << "numbers = " << numbers << ", minr = " << minr<< endl;
	for (int i = minr; i > 0 ; )
	{
		multi = multi * (numbers/i);
		// cout << numbers << " " << i <<  " "<<multi <<  endl;
		numbers--;
		i--;

	}
	// cout << "multi = " << multi << endl;
	return multi;
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