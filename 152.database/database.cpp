#include "database.h"


#include <algorithm>
#include <iostream>
#include <stdexcept>


template <class T, class U>
bool operator == (const std::pair<T, U>& lhs, const std::pair<T, U>& rhs){
    if ((lhs.first == rhs.first) and (lhs.second == rhs.second)){
        return true;
    }
    return false;
} 


void Database::Add(const Date& date, const std::string& event){
    if (database_records_map.count(date) == 0) {
        database_records_map[date] = std::vector<std::string>(0);
    };
    auto location_in_event_vector = std::find(
        database_records_map.at(date).begin(), 
        database_records_map.at(date).end(), 
        event
    );
    if (location_in_event_vector == database_records_map.at(date).end()){
        database_records_map.at(date).push_back(event);
    };
    database_records_set.insert(
        make_pair(date, event)
    );
};


void Database::Print(std::ostream& output_stream) const{
    for (auto it=database_records_set.begin(); it != database_records_set.end(); it++){
        output_stream << it->first << " " << it->second << std::endl;
    };
};


std::vector<std::string> Database::FindIf(std::function<bool(Date, std::string)> predicate) const{
    std::vector<std::string> entries;
    for (auto it=database_records_set.begin(); it != database_records_set.end(); it++){
        if (predicate(it->first, it->second) == true) {
            std::string event;
            std::stringstream string_stream;
            string_stream << it->first << " " << it->second;
            getline(string_stream, event);
            entries.push_back(event);
        }
    };
    return entries;
};


std::string Database::Last(const Date& date) const{
    if (database_records_map.count(date) > 0) {
        if (database_records_map.at(date).size() > 0){
            std::string event;
            std::stringstream string_stream;
            string_stream << date << " " << database_records_map.at(date).back();
            getline(string_stream, event);
            return event;
        }; 
    };
    throw std::invalid_argument("exc");
}


int Database::RemoveIf(std::function<bool(Date, std::string)> predicate){
    const int& initial_size = database_records_set.size();
    for (auto it=database_records_set.begin(); it != database_records_set.end(); it++){
        if (predicate(it->first, it->second) == true) {
            database_records_set.erase(*it);
            database_records_map[it->first].erase(
                std::remove(
                    database_records_map[it->first].begin(),
                    database_records_map[it->first].end(),
                    it->second
                ),
                database_records_map[it->first].end()
            );
        }
    };
    return initial_size - database_records_set.size();
};
