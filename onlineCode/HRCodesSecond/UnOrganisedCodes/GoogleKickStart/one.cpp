#include<bits/stdc++.h>
#include <vector>
using namespace std;

#define flag 1
#define toPrint 1

#ifdef flag
#define pout(x) cout << x
#else
#define pout(x)
#endif


/*
2
4 100
4 80 90 100 5
1 90
1 80
3 80 90 100
3 30
4 10 11 12 13
4 10 11 12 13
5 25 26 27 28 29
*/

void solve(int t){
	long n, s;
	cin >> n >> s;
	
	vector<bitset<1001>> input(n);
	for (int i = 0; i < n; ++i)
	{
		int temp;

		cin >> temp;
		for (int j = 0; j < temp; ++j)
		{
			int val;
			cin >> val;
			input[i][val] = 1;
			// input[i].push_back(val);

		}

	}
	long ret = 0;
	for (int i = 0; i < n; ++i)
	{
		// cout << i <<" --> " ;
		for (int j = 0; j < n; ++j)
		{
			// cout << input[i] << " ";
			long count = ((input[i] | input[j])^input[j]).count();
			if (count > 0) ret++;
			// count = ((input[i] | input[j])^input[j]).count();
			// if (count > 0) ret++;
			
			// cout << count << " ";
		}
		// cout << endl;
	}	

	cout << "Case #" << t << ": " << ret << endl;

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