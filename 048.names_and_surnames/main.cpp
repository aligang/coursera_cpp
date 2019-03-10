#include <string>
#include <iostream>
#include <map>


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
			name_info_element output_info = calculate_actual_name(year);
			if (output_info.first_name == "" && output_info.second_name == ""){
				output = "Incognito";
			} else if (output_info.first_name == "" && output_info.second_name != ""){
				output = output_info.second_name + " with unknown first name" ;
			} else if (output_info.first_name != "" && output_info.second_name == ""){
				output = output_info.first_name + " with unknown last name";
			} else {
				output = output_info.first_name + " " + output_info.second_name;
			}
			return output;
		}
	private:
		struct name_info_element{
			string first_name = "";
			string second_name = "";
			bool was_first_name_modified = false;
			bool was_second_name_modified = false;
		};
		map<int, name_info_element> name_history = {};
		name_info_element calculate_actual_name(const int& year){
			name_info_element output;
			if (name_history.size() != 0){
				for (auto& particular_record:name_history){
					if (particular_record.first <= year){
						if (particular_record.second.first_name != ""){
							output.first_name = particular_record.second.first_name;
						}
						if (particular_record.second.second_name != ""){
							output.second_name = particular_record.second.second_name;
						}
					} else {
						break;
					}
				}
			}
			return  output;
		}
};


int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}
