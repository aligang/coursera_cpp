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


void new_bus(cli_input_element& processing_element, vector<map<string,vector<string>>>& bus_routes){
	map<string, vector<string>> bus_route;
	bus_route.clear();
	for (auto& stop:processing_element.stops){
		bus_route[processing_element.bus_name].push_back(stop);
	}
	bus_routes.push_back(bus_route);
}


vector<string> track_buses_for_stop(const string& current_stop_name, const vector<map<string,vector<string>>>& bus_routes){
	vector<string> buses_passing_current_stop;
	for (auto& bus_route:bus_routes){
		for(auto& bus_name_and_stops:bus_route){
			if (count(bus_name_and_stops.second.begin(), bus_name_and_stops.second.end(), current_stop_name) > 0){
				buses_passing_current_stop.push_back(bus_name_and_stops.first);
			}
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


void track_and_print_buses_for_stop(const cli_input_element& processing_element, const vector<map<string,vector<string>>>& bus_routes){
	int first_stop_index = 0;
	const string& current_stop_name = processing_element.stops[first_stop_index];
	print_buses_for_stop(
		track_buses_for_stop(
			current_stop_name,
			bus_routes
		)
	);
}


map<string,vector<string>> get_bus_info(const string& bus_name, const vector<map<string,vector<string>>>& bus_routes){
	map<string,vector<string>> no_buses;
	for (auto& bus_route:bus_routes){
		if (bus_route.count(bus_name) == 1){
			return bus_route;
			break;
		}
	}
	return no_buses;
}


void stops_for_bus(const cli_input_element& processing_element, const vector<map<string,vector<string>>>& bus_routes){
	const string& bus_name = processing_element.bus_name;
	vector<string> bus_stops;
	vector<string> buses_passing_current_stop;
	vector<string> rest_of_buses_passing_current_stop;
	map<string,vector<string>> bus_route = get_bus_info(bus_name, bus_routes);
	if (bus_route.size() > 0){
		bus_stops = bus_route[bus_name];
		for (auto& current_bus_stop:bus_stops){
			buses_passing_current_stop.clear();
			rest_of_buses_passing_current_stop.clear();
			buses_passing_current_stop = track_buses_for_stop(current_bus_stop, bus_routes);
			copy(buses_passing_current_stop.begin(), buses_passing_current_stop.end(), back_inserter(rest_of_buses_passing_current_stop));
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
				print_buses_for_stop(rest_of_buses_passing_current_stop);
			} else {
				cout << "no interchange" << endl;
			}
		}
	} else {
		cout << "No bus" << endl;
	}
}


void buses(const cli_input_element& processing_element, const vector<map<string,vector<string>>>& bus_routes){
	if (bus_routes.size() > 0){
		for (auto& bus_route:bus_routes){
			for(auto& bus_name_and_stops:bus_route){
				cout << "Bus " << bus_name_and_stops.first << ": ";
				for (auto& stop:bus_name_and_stops.second){
					cout << stop << " ";
				}
				cout << endl;
			}
		}
	} else {
		cout << "No buses" << endl;
	}
}


void process_cli_input(map<int,cli_input_element>& cli_input){
	cli_input_element processing_element;
	vector<map<string,vector<string>>> bus_routes;
	for (auto& element:cli_input){
		processing_element = element.second;
		if (processing_element.operation == "NEW_BUS"){
			new_bus(processing_element, bus_routes);
		} else if (processing_element.operation == "BUSES_FOR_STOP"){
			track_and_print_buses_for_stop(processing_element, bus_routes);
		} else if (processing_element.operation == "STOPS_FOR_BUS"){
			stops_for_bus(processing_element, bus_routes);
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
