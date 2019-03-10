#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
	int number_of_iterations;
	vector<int> input_numbers_to_sort;
	cin >> number_of_iterations;
	input_numbers_to_sort.resize(number_of_iterations);
	for (auto i = 0; i < number_of_iterations; i++){
		cin >> input_numbers_to_sort[i];

	}
	sort(input_numbers_to_sort.begin(), input_numbers_to_sort.end(), [](int x, int y){
		return abs(x) <= abs(y);
		}
	);
	for (auto& number:input_numbers_to_sort){
		cout << number << " ";
	}
}
