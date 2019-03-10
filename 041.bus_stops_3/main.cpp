#include <string>
#include <map>
#include <set>
#include <iostream>


using namespace std;


int main(){
	int number_of_input_iterations, bus_name, number_of_bus_stops;
	string bus_stop;
	set<string> bus_stops;
	map<set<string>, int> bus_routes;
	cin >> number_of_input_iterations;
	bus_name = 1;
	for (auto current_iteration = 0; current_iteration < number_of_input_iterations; current_iteration++){
		cin >> number_of_bus_stops;
		bus_stops.clear();
		for (auto bus_stop_order = 0; bus_stop_order < number_of_bus_stops; bus_stop_order++){
			cin >> bus_stop;
			bus_stops.insert(bus_stop);
		}
		if (bus_routes.count(bus_stops) == 1){
			cout << "Already exists for " << bus_routes[bus_stops] << endl;
		} else {
			bus_routes[bus_stops] = bus_name;
			cout << "New bus " << bus_name << endl;
			bus_name++;
		}
	}
}
