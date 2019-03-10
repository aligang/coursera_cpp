#include <set>
#include <vector>
#include <string>
#include <iostream>


using namespace std;


int main(){
	int amount_of_input_strings;
	string current_string;
	set<string> unique_strings;
	cin >> amount_of_input_strings;
	for (auto i = 0; i < amount_of_input_strings; i++){
		cin >> current_string;
		unique_strings.insert(current_string);
	}
	cout << unique_strings.size();
}
