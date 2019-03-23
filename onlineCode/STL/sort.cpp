#include <iostream>
#include <algorithm>

using namespace std;

int MAX = 10;

void printArray(int *ptr){
	int i = 0;
	for (int i = 0; i < MAX ; ++i) {
		cout << ptr[i] << " ";
		
	}
	cout << endl;
}

int main(int argc, char const *argv[]) {

	int input[10] = {10,4,1,3,5,7,3,2,9,4};
	cout << "Unsorted = " ;
	printArray(input);

	sort(input, input + MAX );
	
	cout << "Sorted = " ;
	printArray(input);

	cout << "Output(6) = " << binary_search(input, input+MAX, 6) << endl;
	cout << "Output(3) = " << binary_search(input, input+MAX, 2) << endl;

	return 0;
}