#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>


using namespace std;


void collect_cli_input(map<int,map<string,string>>& cli_input){
	int number_of_interations;
	cin >> number_of_interations;
	for  (auto i = 0; i < number_of_interations; i++){
		cin >> cli_input[i]["operation"];
		if (cli_input[i]["operation"] == "CHANGE_CAPITAL" || cli_input[i]["operation"] == "RENAME"){
			cin >> cli_input[i]["current_country_name"];
			cin >> cli_input[i]["new_country_name_or_capital_name"];
		} else if (cli_input[i]["operation"] == "ABOUT"){
			cin >> cli_input[i]["current_country_name"];
		}
	}
}


void change_capital(map<string,string>& processing_input_element, map<string,string>& capitals){
	if (capitals.count(processing_input_element["current_country_name"]) == 0){
		capitals[processing_input_element["current_country_name"]] = processing_input_element["new_country_name_or_capital_name"];
		cout << "Introduce new country " << processing_input_element["current_country_name"] << " with capital " << processing_input_element["new_country_name_or_capital_name"] << endl;
	} else {
		if (capitals[processing_input_element["current_country_name"]] == processing_input_element["new_country_name_or_capital_name"]){
			cout << "Country " << processing_input_element["current_country_name"] << " hasn't changed its capital" << endl;
		} else {
			cout << "Country " << processing_input_element["current_country_name"] << " has changed its capital from "
			     << capitals[processing_input_element["current_country_name"]] << " to "<< processing_input_element["new_country_name_or_capital_name"] << endl;
			capitals[processing_input_element["current_country_name"]] = processing_input_element["new_country_name_or_capital_name"];

		}
	}
}


void rename(map<string,string>& processing_input_element, map<string,string>& capitals){
	if (capitals.count(processing_input_element["current_country_name"]) == 0){
		cout << "Incorrect rename, skip" << endl;
	} else {
		if (capitals.count(processing_input_element["new_country_name_or_capital_name"]) == 1){
			cout << "Incorrect rename, skip" << endl;
		} else {
			if (processing_input_element["current_country_name"] == processing_input_element["new_country_name_or_capital_name"]){
				cout << "Incorrect rename, skip" << endl;
			} else {
				capitals[processing_input_element["new_country_name_or_capital_name"]] = capitals[processing_input_element["current_country_name"]];
				cout << "Country " << processing_input_element["current_country_name"] << " with capital " << capitals[processing_input_element["current_country_name"]]
				     << " has been renamed to " << processing_input_element["new_country_name_or_capital_name"] << endl;
				capitals.erase(processing_input_element["current_country_name"]);
			}
		}
	}
}


void about(map<string,string>& processing_input_element, map<string,string>& capitals){
	if (capitals.count(processing_input_element["current_country_name"]) == 0){
		cout << "Country " << processing_input_element["current_country_name"] <<" doesn't exist" << endl;
	} else {
		cout << "Country " << processing_input_element["current_country_name"] << " has capital " << capitals[processing_input_element["current_country_name"]] << endl;
	}
}


void dump(map<string,string>& processing_input_element, map<string,string>& capitals){
	if (capitals.size() > 0){
		for (auto& country:capitals){
			cout << country.first << "/" << country.second << " ";
		}
		cout << endl;
	} else {
		cout << "There are no countries in the world" << endl;
	}
}


void process_cli_nput(map<int,map<string,string>>& cli_input){
	map<string,string> capitals;
	map<string,string> processing_input_element;
	for (auto& cli_input_map_pair:cli_input){
		processing_input_element = cli_input_map_pair.second;
		if (processing_input_element["operation"] == "CHANGE_CAPITAL"){
			change_capital(processing_input_element, capitals);
		} else if (processing_input_element["operation"] == "RENAME"){
			rename(processing_input_element, capitals);
		} else if (processing_input_element["operation"] == "ABOUT"){
			about(processing_input_element, capitals);
		} else if (processing_input_element["operation"] == "DUMP"){
			dump(processing_input_element, capitals);
		}
	}
}


int main(){
	map<int, map<string, string>> cli_input;
	collect_cli_input(cli_input);
	process_cli_nput(cli_input);
}
