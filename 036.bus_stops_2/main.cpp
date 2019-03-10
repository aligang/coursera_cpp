#include <string>
#include <vector>
#include <map>
#include <iostream>


using namespace std;


map<int,vector<string>> collect_cli_input(map<int,vector<string>>& cli_input){
	int amount_of_inputs;
	int amount_of_stops;
	string stop;
	cin >> amount_of_inputs;
	for (auto i = 0; i < amount_of_inputs; i++){
		cin >> amount_of_stops;
		for (auto j = 0; j < amount_of_stops; j++){
			cin >> stop;
			cli_input[i].push_back(stop);
		}
	}
	return cli_input;
}



int get_key_of_element_with_particular_value(const map<int,vector<string>> buses, vector<string> bus_stops){
	int answer = 0;
	for (auto& bus:buses){
		if (bus.second == bus_stops){
			answer = bus.first;
			return answer;
			break;
		}
	}
	return answer;
}


void process_cli_input(const map<int,vector<string>>& cli_input){
	map<int,vector<string>> buses;
	vector<string> bus_stops;
	int next_bus_name = 1;
	int interfering_bus_name ;
	for (auto& cli_input_element:cli_input){
		bus_stops = cli_input_element.second;
		interfering_bus_name = get_key_of_element_with_particular_value(buses, bus_stops);
		if (interfering_bus_name > 0){
			cout << "Already exists for " << interfering_bus_name << endl;
		} else {
			cout << "New bus " << next_bus_name<< endl;
			buses[next_bus_name] = bus_stops;
			next_bus_name++;
		}
	}
}





int main(){
	map<int,vector<string>> cli_input;
	collect_cli_input(cli_input);
	process_cli_input(cli_input);
}
