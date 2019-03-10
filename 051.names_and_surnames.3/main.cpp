#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>



using namespace std;


class Person {
	public:
		Person(const string& first_name_at_birth, const string& second_name_at_birth, const int& year){
			name_history[year].was_first_name_modified = true;
			name_history[year].first_name = first_name_at_birth;
			name_history[year].was_second_name_modified = true;
			name_history[year].second_name = second_name_at_birth;
			year_of_birth = year;
		}


		void ChangeFirstName(const int year, const string& first_name){
			if (year > year_of_birth){
				if (name_history[year].was_first_name_modified == false){
					name_history[year].first_name = first_name;
					name_history[year].was_first_name_modified = true;
				}
			}
		}


		void ChangeLastName(const int year, const string& second_name){
			if (year > year_of_birth){
				if (name_history[year].was_second_name_modified == false){
					name_history[year].second_name = second_name;
					name_history[year].was_second_name_modified = true;
				}
			}
		}


		string GetFullName(const int& year) const{
			string output ;
			if (year >= year_of_birth) {
				return calculate_actual_name(year).first_name + " " + calculate_actual_name(year).second_name;
			} else {
				return "No person";
				}
			}


		string GetFullNameWithHistory(const int& year) const{
			string output ;
			if (year >= year_of_birth) {
			name_info_element name_info_slice = calculate_actual_name(year);
				output = convert_to_string(
					name_info_slice.first_name_history
				) + " "	+ convert_to_string(
					name_info_slice.second_name_history
				);
			} else {
				output = "No person";
			}
			return output;
		}
	private:
		int year_of_birth;
		map<int, name_info_element> name_history = {};
		struct name_info_element{
			string first_name = "";
			string second_name = "";
			bool was_first_name_modified = false;
			bool was_second_name_modified = false;
			vector<string> first_name_history;
			vector<string> second_name_history;
		};


		name_info_element calculate_actual_name(const int& year) const{
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


		string convert_to_string(vector<string>& unique_names) const{
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
  Person person = {"Polina", "Sergeeva", 1960};
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
