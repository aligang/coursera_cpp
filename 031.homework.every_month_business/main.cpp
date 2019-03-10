#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


void collect_shell_input(){

}


struct input_element{
	int day;
	string business;
	string operation;
};


struct data_element{
	int day;
	vector<string> business;
};


void process_cli_input(vector<input_element>& cli_input, int& amount_of_input_elements){
	cin >> amount_of_input_elements;
	for (int i = 0; i < amount_of_input_elements; i++){
		input_element cli_input_element;
		cin >> cli_input_element.operation;
		if (cli_input_element.operation == "ADD"){
			cin >> cli_input_element.day;
			cin >> cli_input_element.business;
		} else if (cli_input_element.operation == "DUMP"){
			cin >> cli_input_element.day;
		}
		cli_input.push_back(cli_input_element);
	}
}


void process_instructions(const vector<input_element>& cli_input){
	int current_month = 0;
	int next_month = 0;
	int months_in_year = 12;
	int amount_of_days_in_current_month, amount_of_days_next_month;
	vector<int> amount_of_days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<vector<string>> business_by_day(amount_of_days_in_months[current_month]);
	for (auto element:cli_input){
		if (element.operation == "ADD"){
			business_by_day[element.day - 1].push_back(element.business);
		} else if (element.operation == "DUMP"){
			cout << business_by_day[element.day - 1].size();
			for (auto business_record:business_by_day[element.day - 1]){
				cout << " " << business_record ;
			}
			cout << endl;
		} else if(element.operation == "NEXT"){
			next_month = (current_month +1) % months_in_year;
			amount_of_days_in_current_month = amount_of_days_in_months[current_month];
			amount_of_days_next_month = amount_of_days_in_months[next_month];
			if (amount_of_days_in_current_month > amount_of_days_next_month){
				for (int i = amount_of_days_next_month; i < amount_of_days_in_current_month; i++){
					business_by_day[amount_of_days_next_month - 1].insert(
						end(business_by_day[amount_of_days_next_month - 1]),
						begin(business_by_day[i]),
						end(business_by_day[i])
					);
					business_by_day[i].clear();
				}
			}
			current_month = next_month;
		}
	}
}



int main(){
	int amount_of_input_elements;
	vector<input_element> cli_input;
	vector<string> operations;
	process_cli_input(cli_input, amount_of_input_elements);
	process_instructions(cli_input);
	return 0;
}
