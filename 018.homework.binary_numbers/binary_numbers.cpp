#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int main(){
	int input_number_decimal;
	vector<int> output_string;
	cin >> input_number_decimal;
	int binary_signs_amount = 1;
//do {
//		 binary_signs_amount++;
//	} while (input_number_decimal >= pow(2, (binary_signs_amount )));
	while (input_number_decimal >= pow(2, binary_signs_amount)){
		binary_signs_amount++;
	}

	for (int i = (binary_signs_amount -1); i >= 0; i--){
		if (input_number_decimal - pow(2, i) >= 0){
			output_string.push_back(1);
			input_number_decimal  -= pow(2, i);
		} else {
			output_string.push_back(0);
		}
	}
	for (auto output_element:output_string){
		cout << output_element;
	}
	return 0;
}
