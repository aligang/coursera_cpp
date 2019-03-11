#pragma once


#include <set>
#include <string>
#include <vector>
#include <map>
#include <functional>

#include "date.h"
#include "condition_parser.h"


class Database {
    public:
        void Add(const Date& date, const std::string& event);
        void Print(std::ostream& output_stream) const; 
        std::vector<std::string> FindIf(std::function<bool(Date, std::string)> predicate) const;
        std::string Last(const Date& date) const;
        int RemoveIf(std::function<bool(Date, std::string)> predicate);

    private:
        std::map<Date,std::vector<std::string>> database_records_map;
        std::set<std::pair<Date, std::string>>  database_records_set;
};
