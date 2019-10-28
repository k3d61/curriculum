#include<bits/stdc++.h>
#include <vector>
using namespace std;


vector<long long> val;
vector<vector<long long>> al;
vector<bool> visited;


long long sum;
long long dp(long long i, bool flag,  long long parent);
void solve(int t){
	sum = 0;
	long n;
	cin >> n;
	val.resize(n+1);
	al.resize(n+1);
	visited.resize(n+1, false);

	for (int i = 1; i <= n; ++i)
	{
		int temp;
		cin >> temp;
		val[i] = temp;

	}
	cout << endl;
	for (int i = 1; i <= n; ++i) cout << val[i] << ", ";
		cout << endl;

	for (int i = 0; i < n-1; ++i)
	{
		long long u, v;
		cin >> u >> v;
		al[u].push_back(v);
		al[v].push_back(u);
	}
	// for (int i = 1; i <= n; ++i)
	// {
	// 	cout << i << " = ";
	// 	for (int j = 0; j < al[i].size(); ++j)
	// 	{
	// 		cout << al[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	long long ret = dp(1, 1,-1);
	ret = ret>0 ? ret : 0;


/*
1
9
-10 4 -10 8 20 30 -2 -3 7
1 4
2 4
4 3
9 4
9 8
7 5
6 7
7 9
*/

	cout << "Case #" << t << ": " << ret << endl;

}

long long dp(long long i, bool flag, long long parent){
	visited[i] = true;

	long long tempSum = 0, tempSum1 = 0, tempSum2 = 0;
	if(flag == true){
		tempSum += val[i];
		cout << i << " " << endl;

		for (int j = 0; j < al[i].size(); ++j)
		{
			long long next = al[i][j];
			if(visited[next] == false){
				tempSum += dp(next, 0, i);
			}
		}
		for (int j = 0; j < al[i].size(); ++j)
		{
			long long next = al[i][j];
			if(parent != -1 && next !=  parent)
				visited[next] = false;
		}
	}
	else{
		tempSum1 += val[i];
		cout << i << " " << endl;

		for (int j = 0; j < al[i].size(); ++j)
		{
			long long next = al[i][j];
			if(visited[next] == false){
				tempSum1 += dp(next, 1, i);
			}
		}
		for (int j = 0; j < al[i].size(); ++j)
		{
			long long next = al[i][j];
			if(parent != -1 && next !=  parent)
				visited[next] = false;
		}



		for (int j = 0; j < al[i].size(); ++j)
		{
			long long next = al[i][j];
			if(visited[next] == false){
				tempSum2 += dp(next, 0, i);
			}
		}
		tempSum = max(tempSum1, tempSum2);
	}

	return tempSum;
}
int main(){

	int t, i=0 ;
	cin >> t;
	while(i < t){	
		solve(i+1);
		i++;
	}

	return 0;


}