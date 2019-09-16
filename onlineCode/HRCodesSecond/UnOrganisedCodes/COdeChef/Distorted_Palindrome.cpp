//https://www.codechef.com/problems/ENCD12

#include <bits/stdc++.h>
// https://www.hackerrank.com/contests/coding-test-3-slot-1/challenges/equalize-the-strings

using namespace std;

int dpi( int i ){
	return i+1;
}

// #define flag 1
#define toPrint 1

#ifdef flag
#define pout(x) cout << x
#else
#define pout(x)
#endif


int dpallingdrom(string a){

	int lena = a.length();
	int count = 0;
	int countOdd = 0;
	int arr[26] = {0};
	for (int i = 0; i < lena; ++i) {
		arr[ a[i] - 'a' ] ++;
	}
	for (int i = 0; i < 26; ++i) {
		arr[i] % 2 ? countOdd++ :countOdd;
	}
	if( countOdd > 1 )
		return -1;


	for(int i = 0 ; i < lena/2 ; ){
		int j = lena-1-i;
		int tempj = j;
		pout ( a[i] << " " << a[j] << endl);
		pout ( a << endl);

		if( a[i] == a[j] ){
			i++;
			continue;
		}
		while( a[i] != a[j] && i < j ){ 
			j--;
		}
		if(i == j){
			char temp = a[i];
			a[i] = a[i+1];
			a[i+1] = temp;
			count++;
			continue;
		}
		else{
			while( j < tempj ){
				char temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				j++;
				count++;
			}
		}
		i++;

	}

	pout (a << endl);

	pout ( "count = " << count << endl);
	return count;
}

int main(){

	string a;
	cin >> a;

	// cout << "a = " << a << endl << "b = " << b << endl;
	pout (endl);
	int ret = dpallingdrom(a);
	if(ret == -1)
		cout << "Impossible" << endl; 
	else
		cout  << ret << endl;
	return 0;
}