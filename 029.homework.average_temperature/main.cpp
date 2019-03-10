#include <vector>
#include <iostream>
using namespace std;


double calculate_average_value(vector<int>& input_values, int& devider){
	int sum_of_elememts = 0;
	for (auto element:input_values){
		sum_of_elememts += element;
	}
	return sum_of_elememts / devider;
}


void assemble_input_vector(vector<int>& input_elements, int& amount_of_elements){
	int input_element;
	for (int i = 0; i < amount_of_elements; i++){
		cin >> input_element;
		input_elements.push_back(input_element);
	}
}


void print_output_information(const int& warm_days_amount, const vector<int>& warm_days_ids){
	cout << warm_days_amount << endl;
	for (auto element:warm_days_ids){
		cout << element << " ";
	}
	cout << endl;
}


int main(){
	int days_amount;
	int warm_days_amount = 0;
	double average_temperature;
	vector<int> temperature_sampling;
	vector<int> warm_days_ids;
	cin >> days_amount;

	assemble_input_vector(temperature_sampling, days_amount);

	average_temperature = calculate_average_value(temperature_sampling, days_amount);
	for (int i = 0; i < temperature_sampling.size(); i++){
		if (temperature_sampling[i] > average_temperature){
			warm_days_amount++;
			warm_days_ids.push_back(i);
		}
	}
	print_output_information(warm_days_amount, warm_days_ids);
}
