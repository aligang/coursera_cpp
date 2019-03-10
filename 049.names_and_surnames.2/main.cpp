#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>



using namespace std;


class Person {
	public:
		void ChangeFirstName(const int year, const string& first_name) {
			// добавить факт изменения имени на first_name в год year
			if (name_history[year].was_first_name_modified == false){
				name_history[year].first_name = first_name;
				name_history[year].was_first_name_modified = true;
			}
		}
		void ChangeLastName(const int year, const string& second_name) {
			// добавить факт изменения фамилии на last_name в год year
			if (name_history[year].was_second_name_modified == false){
				name_history[year].second_name = second_name;
				name_history[year].was_second_name_modified = true;
			}
		}
		string GetFullName(const int& year) {
			// получить имя и фамилию по состоянию на конец года year
			string output ;
			name_info_element name_info_slice = calculate_actual_name(year);
			if (name_info_slice.first_name == "" && name_info_slice.second_name == ""){
				output = "Incognito";
			} else if (name_info_slice.first_name == "" && name_info_slice.second_name != ""){
				output = name_info_slice.second_name + " with unknown first name" ;
			} else if (name_info_slice.first_name != "" && name_info_slice.second_name == ""){
				output = name_info_slice.first_name + " with unknown last name";
			} else {
				output = name_info_slice.first_name + " " + name_info_slice.second_name;
			}
			return output;
		}
		string GetFullNameWithHistory(const int& year) {
			// получить имя и фамилию по состоянию на конец года year
			string output ;
			name_info_element name_info_slice = calculate_actual_name(year);
			if (name_info_slice.first_name == "" && name_info_slice.second_name == ""){
				output = "Incognito";
			} else if (name_info_slice.first_name == "" && name_info_slice.second_name != ""){
				output = convert_to_string(
					name_info_slice.second_name_history
				) + " with unknown first name" ;
			} else if (name_info_slice.first_name != "" && name_info_slice.second_name == ""){
				output = convert_to_string(
					name_info_slice.first_name_history
				) + " with unknown last name";
			} else {
				output = convert_to_string(
					name_info_slice.first_name_history
				) + " "	+ convert_to_string(
					name_info_slice.second_name_history
				);
			}
			return output;
		}
	private:
		struct name_info_element{
			string first_name = "";
			string second_name = "";
			bool was_first_name_modified = false;
			bool was_second_name_modified = false;
			vector<string> first_name_history;
			vector<string> second_name_history;
		};
		map<int, name_info_element> name_history = {};
		name_info_element calculate_actual_name(const int& year){
			name_info_element calculated_name;
			if (name_history.size() != 0){
				for (auto& particular_record:name_history){
					if (particular_record.first <= year){
						if (particular_record.second.first_name != ""){
							calculated_name.first_name = particular_record.second.first_name;
							if (
									(
										calculated_name.first_name_history.size() != 0 &&
										calculated_name.first_name_history[0] != particular_record.second.first_name
									) || (
										calculated_name.first_name_history.size() == 0
									)
							){
								calculated_name.first_name_history.insert(
									calculated_name.first_name_history.begin() + 0,
									particular_record.second.first_name
								);
							}
						}
						if (particular_record.second.second_name != ""){
							calculated_name.second_name = particular_record.second.second_name;
							if (
									(
										calculated_name.second_name_history.size() != 0 &&
										calculated_name.second_name_history[0] != particular_record.second.second_name
									) || (
										calculated_name.second_name_history.size() == 0
									)
							){
								calculated_name.second_name_history.insert(
									calculated_name.second_name_history.begin() + 0,
									particular_record.second.second_name

								);

							}
						}
					} else {
						break;
					}
				}
			}
			return  calculated_name;
		}
		string convert_to_string(vector<string>& unique_names){
			string output_string;
			for (auto i = 0 ; i < unique_names.size(); i++){
				output_string = output_string + unique_names[i];
				if (i >= 1 && (unique_names.size() > 2) && i != (unique_names.size() - 1)){
					output_string = output_string + ",";
				}
				if (i != (unique_names.size() - 1)){
					output_string = output_string + " ";
				}
				if (i == 0 && (unique_names.size() > 1)){
					output_string = output_string + "(";
				}
				if (i == (unique_names.size() - 1) && (unique_names.size() > 1)){
					output_string = output_string + ")";
				}
			}
			return output_string;
		}
};



int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeFirstName(1966, "Pelageya");
  person.ChangeLastName(1967, "Sergeeva");
  person.ChangeLastName(1968, "Sergeeva");
  person.ChangeLastName(1969, "Sergeeva");
  cout << person.GetFullNameWithHistory(1970) << endl;
  return 0;
}
