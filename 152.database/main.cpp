#include <iostream>
#include <stdexcept>
#include <string>


#include "database.h"
#include "date.h"
#include "test_runner.h"


using namespace std;


const string ParseEvent(istream& input_stream) {
    string event;
    string raw_event;
    getline(input_stream, raw_event);
    for (auto it = raw_event.begin(); it != raw_event.end(); it++){
        if (event.size() == 0){
            if (*it == ' ') {
                 continue;
            }
            else if (
                *it == '"' and *(prev(raw_event.end())) != '"'
            ){
                continue;
            } 
            else {
                event += *it;
            }
        }
        else if (event.size() == 1 and it != prev(raw_event.end())){
            if (
                 *it == ' ' and event[0] == '"'
            ){
                continue;
            }
            else if (
                *it == ' ' and *(next(it)) == ' '
            ){
                continue;
            }
            else {
                event += *it;
            }
        }
        else if (event.size() > 1 and next(it) != prev(raw_event.end()) and it != prev(raw_event.end())){
            if (
                *it == ' ' and *(next(it)) == ' '
            ){ 
                continue;
            }
            else {
                event += *it;
            }
        }
        else if (next(it) == prev(raw_event.end())){
            if (*it == ' ' and *prev(raw_event.end()) == '"') {
                continue;
            } else if (*it == ' ' and *prev(raw_event.end()) == ' '){
                continue;
            } else {
                event += *it;
            }
        }
        else if (it == prev(raw_event.end())){
            if (*it == '"' and event[0] != '"') {
                continue;
            } else if (*it == ' '){
                continue;
            } else {
                event += *it;
            }
        }
    }
    return event;
}



void TestParseEvent() {
    {
        std::istringstream is("event");
        AssertEqual(ParseEvent(is), "event", "Parse event without leading spaces");
    }
    {
        std::istringstream is("     sport event ");
        AssertEqual(ParseEvent(is), "sport event", "Parse event with leading spaces");
    }
    {
        std::istringstream is("     sport   event   ");
        AssertEqual(ParseEvent(is), "sport event", "Parse event with leading spaces");
    }
    {
        std::istringstream is("     sport   event   ");
        AssertEqual(ParseEvent(is), "sport event", "Parse event with leading spaces");
    }
//    {
//        istringstream is("    first event    \n    second event");
//        vector<string> events;
//        events.push_back(ParseEvent(is));
//        events.push_back(ParseEvent(is));
//        AssertEqual(events, vector<string>{"first event    ", "second event"}, "Parse multiple events");
//   }
}


void TestAll() {
    TestRunner tr;
    tr.RunTest(TestParseEvent, "TestParseEvent");
//    tr.RunTest(TestParseCondition, "TestParseCondition");
}


int main() {
    TestAll();
    Database db;
    for (string line; getline(cin, line); ) {
        istringstream is(line);
        string command;
        is >> command;
        if (command == "Add") {
            const auto date = ParseDate(is);
            const auto event = ParseEvent(is);
            db.Add(date, event);
        } else if (command == "Print") {
            db.Print(cout);
        } else if (command == "Del") {
            auto condition = ParseCondition(is);
            auto predicate = [condition](const Date& date, const string& event) {
                return condition->Evaluate(date, event);
            };
            int count = db.RemoveIf(predicate);
            cout << "Removed " << count << " entries" << endl;
        } else if (command == "Find") {
            auto condition = ParseCondition(is);
            auto predicate = [condition](const Date& date, const string& event) {
                return condition->Evaluate(date, event);
            };
            const auto entries = db.FindIf(predicate);
            for (const auto& entry : entries) {
                cout << entry << endl;
            }
            cout << "Found " << entries.size() << " entries" << endl;
        } else if (command == "Last") {
            try {
                cout << db.Last(ParseDate(is)) << endl;
            } catch (invalid_argument&) {
                    cout << "No entries" << endl;
            }
        } else if (command.empty()) {
            continue;
        } else {
            throw logic_error("Unknown command: " + command);
        };
    };
    return 0;
}