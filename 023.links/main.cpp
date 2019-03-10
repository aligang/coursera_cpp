#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


void swap(int& a, int& b){
	int buffer = a;
	a = b;
	b = buffer;
}


void custom_sort(vector<int>& v){
	sort(begin(v), end(v));
}


int main(){
	int a = 2;
	int b = 3;
	swap(a, b);
	cout << "a = " << a << "\n";
	cout << "b = " << b;

	vector<int> numbers = {1, 2, 10, 9, 8, 7, 3, 4};
	custom_sort(numbers);
	for (auto number:numbers){
		cout << number << " ";
	}
}
