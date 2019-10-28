#include <bits/stdc++.h>
#include <string>

using namespace  std;

string input;

 // input : 675356291270936062618792

// 0 you can still use this bit for 2 bit way
// 1 last bit was taken in 2 bit way
long dp(long i){

	if(i >= input.length()) return 1;
	cout << i << endl;

	long sum =0;
	sum += dp(i+1);
	if( i+2 <= input.length()){
		long t1 = (input[i]-'0')*10 + (input[i+1]-'0');
		if(t1 < 27)
			sum += dp(i+2);
	}

	return sum;
}


int main(){

	cin >> input;
	cout << input.length() << endl;
	long sum = 0;

	sum += dp(0);

	cout << endl;
	cout << "ret = " << sum << endl;
	return 0;
}