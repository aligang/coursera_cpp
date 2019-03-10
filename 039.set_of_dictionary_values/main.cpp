#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>


using namespace std;


set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> set_of_values;
	for (auto& pair:m){
		set_of_values.insert(pair.second);
	}
	return set_of_values;
}


void print_set(const set<string>& set_to_print){
	for (auto& element:set_to_print){
		cout << element << endl;
	}
}


int main(){
	set<string> set_of_values;
	map<int, string> test_dict = {
		    {1, "odd"},
		    {2, "even"},
		    {3, "odd"},
		    {4, "even"},
		    {5, "odd"}
		};
	set_of_values = BuildMapValuesSet(test_dict);
	print_set(set_of_values);

}
