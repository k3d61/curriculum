// https://www.geeksforgeeks.org/urlify-given-string-replace-spaces/
#include <bits/stdc++.h>
// #include <pair.h>

// https://www.geeksforgeeks.org/replace-every-element-with-the-least-greater-element-on-its-right/

std::set<int> temp;
int customFunc(int a){
	temp.insert(a);
	auto it = upper_bound(temp.begin(), temp.end(), a);

	if( it != temp.end() ) 
		return *it;
	return -1;
	// std::cout << ">> " << b << std::endl; 
	// return b;
}

int main(){

	
    std::vector<int> v = { 8, 58, 71, 18, 31, 32, 63, 92, 
                  43, 3, 91, 93, 25, 80, 28 };

    transform(v.rbegin(), v.rend(), v.rbegin(), customFunc );

    for(auto i : v) std::cout << i << " ";
    std::cout << std::endl;
	return 0;
}