#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int main(){
	int number_of_iterations;
	vector<string> input_strings_to_sort;
	cin >> number_of_iterations;
	input_strings_to_sort.resize(number_of_iterations);
	for (auto i = 0; i < number_of_iterations; i++){
		cin >> input_strings_to_sort[i];

	}
	sort(input_strings_to_sort.begin(), input_strings_to_sort.end(), [](string string_1, string string_2){
			transform(string_1.begin(), string_1.end(), string_1.begin(), ::tolower);
			transform(string_2.begin(), string_2.end(), string_2.begin(), ::tolower);
			return string_1 <= string_2;
		}
	);
	for (auto& output_string:input_strings_to_sort){
		cout << output_string << " ";
	}
}
