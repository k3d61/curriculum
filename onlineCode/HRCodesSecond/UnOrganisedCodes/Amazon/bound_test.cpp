#include <bits/stdc++.h>
// #include <pair.h>
int accumulateFunc(int a, int b){
	return a*b;
}

std::pair<int, int> calcLength(  std::pair<int, int> a, int b){
	if(b%2 == 0) a.second++;
	else a.first++;

	return a;
}
int main(){

	int arr[] = {10, 20, 30 , 40};
	std::vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));

	for(auto a:v){
		std::cout << a << std::endl;
	}

	std::cout << std:: endl << *upper_bound(v.begin(), v.end(), 30) << std::endl;
	std::cout << *lower_bound(v.begin(), v.end(), 30) << std::endl;
	
	std:: cout<< "accumulate " << accumulate( v.begin(), v.end(), 
		1, accumulateFunc ) << std::endl;


	int evenOdd[] = {2,3,5,6,9, 40};
	std::vector<int> veo(evenOdd, evenOdd + sizeof(evenOdd)/sizeof(evenOdd[0]));

	std::pair<int, int> init(0,0);
	// init.first = 0;
	// init.second = 0;
	std::pair<int, int> ret = accumulate( veo.begin(), veo.end(), std::make_pair(0,0), calcLength );
	std::cout << "lpogest str = " << ret.first << " " << ret.second << std:: endl;
	return 0;
}