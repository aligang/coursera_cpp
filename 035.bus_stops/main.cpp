#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>


using namespace std;


struct cli_input_element{
	string operation;
	string bus_name;
	vector<string> stops;
};


void collect_cli_input(map<int,cli_input_element>& cli_input){
	int number_input_records;
	int number_of_bus_stops;
	string input_command;
	string bus_name;
	string stop;
	cin >> number_input_records;
	for  (auto i = 0; i < number_input_records; i++){
		cin >> cli_input[i].operation;
		if (cli_input[i].operation == "NEW_BUS"){
			cin >> cli_input[i].bus_name;
			cin >> number_of_bus_stops;
			for  (auto j = 0; j < number_of_bus_stops; j++){
				cin >> stop;
				cli_input[i].stops.push_back(stop);
			}
		} else if (cli_input[i].operation == "BUSES_FOR_STOP"){
			cin >> stop;
			cli_input[i].stops.push_back(stop);
		} else if (cli_input[i].operation == "STOPS_FOR_BUS"){
			cin >> cli_input[i].bus_name;
		} else if (cli_input[i].operation == "BUSES"){
			//ничо не делать
		}
	}
}


void new_bus(cli_input_element& processing_element, map<string,vector<string>>& bus_routes, vector<string>& bus_register){
	for (auto& stop:processing_element.stops){
		bus_routes[processing_element.bus_name].push_back(stop);
	}
	bus_register.push_back(processing_element.bus_name);
}


vector<string> track_buses_for_stop(const string& current_stop_name, const map<string,vector<string>>& bus_routes){
	vector<string> buses_passing_current_stop;
	for (auto& bus_route:bus_routes){
		if (count(bus_route.second.begin(), bus_route.second.end(), current_stop_name) > 0){
			buses_passing_current_stop.push_back(bus_route.first);
		}
	}
	return buses_passing_current_stop;

}


void print_buses_for_stop(const vector<string>& buses_passing_current_stop){
	if (buses_passing_current_stop.size() > 0){
		for (auto& bus:buses_passing_current_stop){
			cout << bus << " ";
		}
		cout << endl;
	} else {
		cout << "No stop" << endl;
	}
}

void print_buses_for_stop_by_date(const vector<string>& buses_passing_current_stop, const vector<string>& bus_register){
	if (buses_passing_current_stop.size() > 0){
		for (auto& bus_name:bus_register){
			if ( count(buses_passing_current_stop.begin(), buses_passing_current_stop.end(), bus_name) > 0){
				cout << bus_name << " ";
			}
		}
		cout << endl;
	} else {
		cout << "No stop" << endl;
	}
}


void check_and_print_buses_for_stop(const cli_input_element& processing_element, const map<string,vector<string>>& bus_routes, const vector<string>& bus_register){
	int first_stop_index = 0;
	const string& current_stop_name = processing_element.stops[first_stop_index];
	print_buses_for_stop_by_date(
		track_buses_for_stop(
			current_stop_name,
			bus_routes
		),
		bus_register
	);
}


void stops_for_bus(const cli_input_element& processing_element, map<string,vector<string>>& bus_routes, const vector<string>& bus_register){
	const string& bus_name = processing_element.bus_name;
	vector<string> buses_passing_current_stop;
	vector<string> rest_of_buses_passing_current_stop;
	if (bus_routes.count(processing_element.bus_name) == 1){
		for (auto current_bus_stop:bus_routes[bus_name]){

			buses_passing_current_stop = track_buses_for_stop(current_bus_stop, bus_routes);
/			copy(buses_passing_current_stop.begin(), buses_passing_current_stop.end(), back_inserter(rest_of_buses_passing_current_stop));
			rest_of_buses_passing_current_stop = buses_passing_current_stop;
			rest_of_buses_passing_current_stop.erase(
				remove(
					rest_of_buses_passing_current_stop.begin(),
					rest_of_buses_passing_current_stop.end(),
					bus_name
				),
				rest_of_buses_passing_current_stop.end()
			);
			cout << "Stop " <<current_bus_stop << ": ";
			if (rest_of_buses_passing_current_stop.size() > 0){
				print_buses_for_stop_by_date(rest_of_buses_passing_current_stop, bus_register);
			} else {
				cout << "no interchange" << endl;
			}
		}
	} else {
		cout << "No bus" << endl;
	}
}


void buses(cli_input_element& processing_element, map<string,vector<string>>& bus_routes){
	if (bus_routes.size() > 0){
		for (auto& bus_route:bus_routes){
			cout << "Bus " << bus_route.first << ": ";
			for (auto& stop:bus_route.second){
				cout << stop << " ";
			}
			cout << endl;
		}
	} else {
		cout << "No buses" << endl;
	}
}


void process_cli_input(map<int,cli_input_element>& cli_input){
	cli_input_element processing_element;
	map<string,vector<string>> bus_routes;
	vector<string> bus_register;
	for (auto element:cli_input){
		processing_element = element.second;
		if (processing_element.operation == "NEW_BUS"){
			new_bus(processing_element, bus_routes, bus_register);
		} else if (processing_element.operation == "BUSES_FOR_STOP"){
			check_and_print_buses_for_stop(processing_element, bus_routes, bus_register);
		} else if (processing_element.operation == "STOPS_FOR_BUS"){
			stops_for_bus(processing_element, bus_routes, bus_register);
		} else if (processing_element.operation == "ALL_BUSES"){
			buses(processing_element, bus_routes);
		}

	}
}

int main(){
	map<int,cli_input_element> cli_input;
	collect_cli_input(cli_input);
	process_cli_input(cli_input);
	return 0;
}
