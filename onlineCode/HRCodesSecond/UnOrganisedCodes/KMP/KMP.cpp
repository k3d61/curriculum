#include <bits/stdc++.h>
using namespace std;

vector<int> suffixArr;
void suffixMatching( string in){

	for( int i=1, j=0 ;  i < in.length();){
		// cout << i << " : "<< in[i] << ", " << j << " : " << in[j] << endl;
		if(in[j] == in[i]){
			suffixArr[i++] = ++j;
		}
		else{
			if( j != 0 ) 
				j = suffixArr[ j-1 ];
			else
				suffixArr[i++] = 0;
		}
	}

	cout << endl;
	for( int i=0 ;  i < in.length(); i++ )	cout << in[i] << " ";
	cout << endl;
	for( int i=0 ;  i < in.length(); i++ ) cout << suffixArr[i] << " ";	
	cout << endl;
}
int patternMatching(string a, string b){
	suffixArr.resize( b.length() );
	suffixMatching(b);

	cout << endl;
	for( int i=0 ;  i < a.length(); i++ )	cout << a[i] << " ";
	cout << endl;
	for( int i=0 ;  i < b.length(); i++ ) cout << b[i] << " ";	
	cout << endl;

	for(int i = 0, j = 0 ; i < a.length() ; ){
		cout << i << " : " << a[i] << endl;
		cout << j << " : " << b[j] << endl << endl;
		if( a[i] == b[j] ){
			i++;
			j++;
			if( j == b.length()-1){
				cout << "Pattern found @=" << i-j << endl;
			}
		}
		else{
			if( j != 0){
				j = suffixArr[j-1];
			}
			else
				i++;
		}
		
	}
	
}
int main(){

	string a = "ABABDABACDABABCABAB";
	string b = "ABABCABAB"; //abacababa
	patternMatching(a, b);
	return 0;
}