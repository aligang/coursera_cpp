#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>


using namespace std;


enum  QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};


struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};


istream& operator >> (istream& is, QueryType& query_type) {
  string buffer;
  is >> buffer;
    if (buffer == "NEW_BUS"){
        query_type = QueryType::NewBus;
    } else if (buffer == "BUSES_FOR_STOP"){
        query_type = QueryType::BusesForStop;
    } else if (buffer == "STOPS_FOR_BUS"){
        query_type = QueryType::StopsForBus;
    } else if (buffer == "ALL_BUSES"){
        query_type = QueryType::AllBuses;
    }

  return is;
}


istream& operator >> (istream& is, Query& q) {
    is >> q.type;
    switch (q.type) {
        case QueryType::NewBus:
            is >> q.bus;
            int bus_count;
            is >> bus_count; 
            q.stops.clear();
            for (auto i = 0; i < bus_count; i++){
                is >> q.stop;
                q.stops.push_back(q.stop);
            }
            break;
        case QueryType::BusesForStop:
            is >> q.stop;
            break;
        case QueryType::StopsForBus:
            is >> q.bus;
            break;
        case QueryType::AllBuses:
            break;
    }
    return is;
}


struct BusesForStopResponse {
  // Наполните полями эту структуру
  bool present;
  vector<string> buses;
};


ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // Реализуйте эту функцию
    if (r.present == false){
        os << "No stop" << endl;
    } else {
        for (const string& bus: r.buses) {
          os << bus << " ";
        }
        os << endl;
    }
    return os;
}

struct Interchanges{
    string stop_name;
    bool present;
    vector<string> buses;
};


struct StopsForBusResponse {
  // Наполните полями эту структуру
    bool present;
    vector<Interchanges> stops_with_interchanges;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
    if (r.present == false){
        cout << "No bus" << endl;
    } else {
        for (const auto& stop_with_interchanges: r.stops_with_interchanges){
            os << "Stop " << stop_with_interchanges.stop_name << ": ";
            if (stop_with_interchanges.present == false) {
                cout << "no interchange";
            } else {
                for (const string& bus: stop_with_interchanges.buses) {
                    os << bus << " ";
                }
            }
            os << endl;
        }
    }
    return os;
}

struct AllBusesResponse {
  // Наполните полями эту структуру
    bool present;
    map<string, vector<string> > bus_routes;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // Реализуйте эту функцию
    if (r.present == false) {
        os << "No buses" << endl;
    } else {
        for (const auto& bus_route: r.bus_routes) {
            os << "Bus " << bus_route.first << ": ";
            for (const string& stop: bus_route.second) {
                os << stop << " ";
            }
            os << endl;
        }
    }
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
        for(auto stop: stops){
            buses_to_stops[bus].push_back(stop);
            stops_to_buses[stop].push_back(bus); 
        }
    }


    BusesForStopResponse GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
        BusesForStopResponse output;
        if (stops_to_buses.count(stop) == 0) {
            output.present = false;
        } else {
            output.present = true;
            for (const string& bus: stops_to_buses.at(stop)) {
                output.buses.push_back(bus);
            }
        }
        return output;
    }


    StopsForBusResponse GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
        StopsForBusResponse output; 
        if (buses_to_stops.count(bus) == 0) {
            output.present = false;
        } else {
            output.present = true;
            for (const string& stop: buses_to_stops.at(bus)) {
                Interchanges interchanges;
                interchanges.stop_name = stop;
                if (stops_to_buses.at(stop).size() == 1) {
                    interchanges.present = false;
                } else {
                    interchanges.present = true;
                    for (const string& other_bus: stops_to_buses.at(stop)) {
                        if (bus != other_bus) {
                            interchanges.buses.push_back(other_bus);
                        }
                    }
                }
                output.stops_with_interchanges.push_back(interchanges);
            }
        }
        return output;
    }


    AllBusesResponse GetAllBuses() const {
    // Реализуйте этот метод
        AllBusesResponse output;
        if (buses_to_stops.empty()) {
            output.present = false;
        } else {
            output.present = true;
            output.bus_routes = buses_to_stops;
        }
        return output;
    }


private:
    map<string, vector<string> > buses_to_stops;
    map<string, vector<string> > stops_to_buses;  
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
    int query_count;
    Query q;
    cin >> query_count;
    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }
    return 0;
}
