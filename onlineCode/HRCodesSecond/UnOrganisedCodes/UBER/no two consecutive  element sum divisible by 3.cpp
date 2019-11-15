#include <bits/stdc++.h>

// 1110222 yes
//  01122 no
//  10001 no ceil(n/1) zeros
using namespace std;

/*
7
11
1 1 0 0 0 0 0 0 2 2 2
9
1 1 0 0 0 0 0 0 2
6 
0 1 0 1 2 2 
4 
0 0 0 1
4
1 2 1 2
4
2 2 2 1 
5
0 0 0 2 2


*/
// #define pout(x) cout << x
#define pout(x) 


void solve(  ){
	int n; cin >> n;
	// std::vector<int> v = {0,1,2,2,2,2,1,1,,2,2,0,0,0,0,0,0};
	 std::vector<int> v(n);
	 
	 pout (  "\nin = ");
	 
	 int zero=0, one=0, two=0;
	 for(int i = 0 ; i < n ; i++){
	 	cin >> v[i];
	 	pout (  v[i] << " "); 
	 	if(v[i] %3 == 0) zero++;
	 	if(v[i] %3 == 1) one++;
	 	if(v[i] %3 == 2) two++;
	 	
	 } 
	 cout << endl;

	 	 
	 if(((n%2==0) && (ceil(n/2) < zero)) || ((n%2==1) && (ceil(n/2)+1 < zero)) ||
	  (zero == 0 && one > 0 && two > 0) ){
		cout << "-1" ;
		pout ( endl << "-------------------------------------------");
	  return;
	}
	if( zero < one+two ){
		pout ( "#0->" << zero << ", #1->" << one << ", #2->" << two << endl);
 		list<int> ret;
		auto it = ret.begin(); 
		ret.insert(it, one, 1 );
		ret.insert(it, two, 2 );
		it = upper_bound( ret.begin(), ret.end(), 1 );
			
		ret.insert(it, 0);
		zero--;
		it = ret.begin();
		while(zero != 0 ){
			if( *it != 0 && *(++it) !=0 ){
				it--;
				ret.insert( it, 0 );
			}
			zero--;
		}

		pout (  endl << "ret = ");
		for(auto a: ret)
			cout << a << " " ; 

		pout (  endl << "-------------------------------------------");
		return;
	}	
	if( zero >= one+two ){
		pout (  "#0->" << zero << ", #1->" << one << ", #2->" << two << endl);
 		list<int> ret;
		auto it = ret.begin(); 
		ret.insert(it, zero, 0 );
		
		it = ret.begin();
		it++;
		while(one != 0 ){
			ret.insert(it, 1);
			it++;
			// it++;
			one--;
		}
		while(two != 0 ){
			ret.insert(it, 2);
			it++;
			// it++;
			two--;
		}

		pout (  endl << "ret = ");
		for(auto a: ret)
			cout << a << " " ; 

		pout (  endl << "-------------------------------------------");
		return;
	}	



	pout (  endl << "-------------------------------------------");
}
int main(){


	int t;
	cin >> t;
	while(t--) solve();
	 cout << endl;
	return 0;
}