#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>


using namespace std;


void collect_input(const string& path, vector<vector<int>>& table){
	string single_input_string;
	ifstream input(path);
	if (input){
		int total_amount_of_table_strings, total_amount_of_table_columns, element;
		input >> total_amount_of_table_strings;
		input.ignore(1);
		input >> total_amount_of_table_columns;
		input.ignore(1);

		for (auto i = 0; i < total_amount_of_table_strings; i++){
			table.push_back({});
			for (auto j = 0; j < total_amount_of_table_columns; j++){
				input >> element;
				input.ignore(1);
				table[i].push_back(
						element
				);
			}
		}
	}
}


void display_output(const vector<vector<int>>& table){
	if (table.size() > 0) {
		cout << right;
		for (const auto& display_string:table){
			for ( auto i = 0; i < display_string.size(); i++){
				cout << setw(10);
				cout << display_string[i];
				if (i < (display_string.size() - 1)){
					cout << " ";
				}
			}
			cout << endl;
		}
	}
}


int main(){
	const string path = "input.txt";
	vector<vector<int>> table;
	collect_input(path, table);
	display_output(table);
}

