#include <string>
#include <vector>
#include <iostream>
using namespace std;


void Reverse(vector<int>& numbers){
	vector<int> buffer;
	for (auto number:numbers){
		buffer.insert(buffer.begin(), number);
	}
	numbers = buffer;
}

void print_list_content(const vector<int>& vector_to_print){
	cout << "contains: ";
	for (auto element:vector_to_print){
		cout << element << ", ";
	}
}


int main(){
	vector<int> numbers = {1, 5, 3, 4, 2};
	Reverse(numbers);
	print_list_content(numbers);
	return 0;
}
