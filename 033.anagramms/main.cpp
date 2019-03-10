#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;


map<int, vector<string>> collect_cli_input(){
	int amount_of_interations;
	string input_string;
	map<int, vector<string>> cli_input;
	cin >> amount_of_interations;
	for(auto i = 0; i < amount_of_interations; i++){
		for(auto j = 0; j < 2; j++){
			cin >> input_string;
			cli_input[i].push_back(input_string);
		}
	}
	return cli_input;
}


map<char, int> BuildCharCounters(const string& word){
	map<char, int> char_counters;
	for (auto& letter:word){
		char_counters[letter]++;
	}
	return char_counters;
}


string check_single_block_for_anagramms(const vector<string>& vector_of_strings){
	string result = "YES";
	vector<map<char, int>> char_counters;
	for (auto& element:vector_of_strings){
		char_counters.push_back(BuildCharCounters(element));
	}
	for (auto& element:char_counters){
		if (element != char_counters[0]){
			result = "NO";
		}
	}
	return result;
}


map<int, string> check_input_for_anagramms(const map<int,vector<string>> input_dictionary){
	map<int, string> output_dictionary;
	for (const auto& element:input_dictionary){
		output_dictionary[element.first] = check_single_block_for_anagramms(element.second);
	}
	return output_dictionary;
}


void print_output(map<int,string>& dict_to_print){
	for(auto& element:dict_to_print){
		cout << element.second << endl;
	}
}


int main(){
	map<int, vector<string>> cli_input;
	map<int,string> dict_of_anagramms;
	cli_input = collect_cli_input();
	dict_of_anagramms = check_input_for_anagramms(cli_input);
	print_output(dict_of_anagramms);
}
