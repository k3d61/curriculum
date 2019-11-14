#include <bits/stdc++.h>

using namespace std;

#include <vector>
#include <stack>
#include <utility>

int solve( string in, int k){

	stack<pair<char,int>> stk;
	for(int i = 0 ; i < in.length() ; i++){
		cout << in[i] << " ";
		if(stk.empty() || in[i] != stk.top().first) {
			cout << "push" << endl;
			stk.push( make_pair( in[i], 1 ) );
		}
		else if( stk.top().second == k-1 ){
			cout << "pop" << endl;
			for(int j = 0 ; j < k-1 ; j++ ){
				stk.pop();
			}
		}
		else{
			cout << "push 2" << endl;
			stk.push( make_pair( in[i],2 ) );
		}
	}

	cout << endl;
	while(!stk.empty()){
		cout << stk.top().first;
		stk.pop();
	}
	return 0;
// geeksforgeeks
// qddxxxd 3
}

int main(){

	string in;
	int k;
	cin >> in >> k;
	solve(in, k);
	cout << endl;
	return 0;
}