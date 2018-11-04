/*
 * Author : Kedar
 * Problem Statement : https://www.codechef.com/NOV18B/problems/CHHAPPY/
 */

#include <fstream>
#include <algorithm>
#include <iterator>
#include <string.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int A[1000000] = {0}; 
int Ai[1000000] = {-1}; 

int main(){
	int T, N;
	cin >> T;
	while(T--){
	
		memset(Ai, 0, sizeof(Ai));
		vector<pair<int,int> >As;
		cin >> N;
		int i, j;

		// dummy push
		As.push_back (make_pair (0,0));
		for ( i = 1 ; i <= N ; i++) {
			cin >> A[i];
	    	As.push_back (make_pair (A[i],i)); // k = value, i = original index
		}
		
		sort ( As.begin(), As.end());

		// inverted array
		for ( i = 1 ; i <= N ; i++) {
			Ai[A[i]] = i;		
		}

		// for (i = 1 ; i <= N  ; i++)
		// 	cout << As[i].first <<  " ";
		// cout << endl;
		// for (i = 1 ; i <= N  ; i++)
		// 	cout << Ai[i] <<  " ";


		int flag = 0;
		for (int i = 2; i <= N; ++i){
			int a = As[i-1].first;
			int ai = As[i-1].second;

			int b = As[i].first;
			int bi = As[i].second;
			
			// cout << endl; 
			// cout << " --> "<< a << " " << b << " "  << endl;
			// cout << " => "<< ai << " " << bi << " " <<  flag<<  endl;
			if (( a == b) && ( Ai[bi] != 0 ) && (Ai[ai] != 0) )
				flag = 1;
		}
		
		if (flag == 1)
			cout << "Truly Happy" << endl;
		else
			cout << "Poor Chef" << endl;
					
	}
	

	// for (int i = 0 ;i < T ; i++) {
	//     // filling the original array
	//     cin >> k;
	// 	a.push_back (make_pair (A[i],i)); // k = value, i = original index
	// }

	// sort (a.begin(),a.end());

	// for (int i = 0 ; i < T ; i++){
	//     cout << a[i].first << " " << a[i].second << "\n";
	// }
	
	return 0;
}