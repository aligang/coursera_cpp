#include <string>
#include <vector>
#include <iostream>
using namespace std;


vector<int> Reversed(const vector<int>& v){
	vector<int> reversed_vector;
	for (auto number:v){
		reversed_vector.insert(reversed_vector.begin(), number);
	}
	return reversed_vector;
}


void print_list_content(const vector<int>& vector_to_print){
	cout << "contains: ";
	for (auto element:vector_to_print){
		cout << element << ", ";
	}
}


int main(){
	vector<int> numbers = {1, 5, 3, 4, 2};
	vector<int> reversed_numbers = Reversed(numbers);
	print_list_content(reversed_numbers);
	return 0;
}
