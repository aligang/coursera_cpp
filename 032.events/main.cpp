#include <iostream>
#include <string>
#include <map>
#include <vector>


using namespace std;


void print_map(const map<int, string>& some_map){
	cout << "size is: " << some_map.size() << endl;
	for (auto element:some_map){
		cout << element.first <<" is year of " << element.second;
		cout << endl;
	}
}


void print_reverse_map(const map<string, int>& some_map){
	cout << "size is: " << some_map.size() << endl;
	for (const auto& element:some_map){
		cout << element.first <<" is year of " << element.second;
		cout << endl;
	}
}


void print_dictionary(const map<string, int>& some_map){
	cout << "size is: " << some_map.size() << endl;
	for (const auto& element:some_map){
		cout << "element " <<element.first <<" appears " << element.second << " times";
		cout << endl;
	}
}


map<string, int> build_reverse_map(const map<int, string>& some_map){
	map<string, int> reverse_map;
	for (auto pair:some_map){
		reverse_map[pair.second] = pair.first;
	}
	return reverse_map;
}

void count_elements(const vector<string> some_vector, map<string, int>& some_dict){
	for (const auto& element:some_vector){
		++some_dict[element];
	}
	some_dict["bla-bla"];
}



int main(){
	map<int, string> events;
	events = {{1988, ""},{1995, ""}};
	events[1988] = "birth";
	events[1995] = "first day at school";
	events[1997] = "third class";
	print_map(events);
	cout << events[1988] << endl;
	events.erase(1997);
	print_map(events);
	print_reverse_map(build_reverse_map(events));
	vector<string> words = {"one", "two", "two", "three", "three", "three"};
	map<string, int> counters;
	count_elements(words, counters);
	print_dictionary(counters);
	cout << counters.count("one") << endl;
	cout << counters.count("five") << endl;
}
