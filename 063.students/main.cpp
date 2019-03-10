#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct FirstName{
	string value;
	explicit FirstName(const string& first_name){
		value = first_name;
	}
};


struct LastName{
	string value;
	explicit LastName(const string& last_name){
		value = last_name;
	}
};


struct DayOfBirth{
	int value;
	explicit DayOfBirth(const int& day_of_birth){
		value = day_of_birth;
	}
};


struct MonthOfBirth{
	int value;
	explicit MonthOfBirth(const int& month_of_birth){
		value = month_of_birth;
	}
};


struct YearOfBirth{
	int value;
	explicit YearOfBirth(const int& year_of_birth){
		value = year_of_birth;
	}
};


struct Student{
	string first_name;
	string last_name;
	int day_of_birth;
	int month_of_birth;
	int year_of_birth;
	Student(
		FirstName first_name_input,
		LastName last_name_input,
		DayOfBirth day_of_birth_input,
		MonthOfBirth month_of_birth_input,
		YearOfBirth year_of_birth_input
	){
		first_name = first_name_input.value;
		last_name = last_name_input.value;
		day_of_birth = day_of_birth_input.value ,
		month_of_birth =  month_of_birth_input.value,
		year_of_birth = year_of_birth_input.value;

	}
};


vector<Student> collect_input(){
	int amount_of_data_inputs;
	int day_of_birth;
	int month_of_birth;
	int year_of_birth;
	string first_name;
	string last_name;
	vector<Student> students;
	cin >> amount_of_data_inputs;
	for (auto i = 0; i < amount_of_data_inputs; i++){
		cin >> first_name >> last_name >> day_of_birth >> month_of_birth >> year_of_birth;
		students.push_back(
			{
				FirstName(first_name),
				LastName(last_name),
				DayOfBirth(day_of_birth),
				MonthOfBirth(month_of_birth),
				YearOfBirth(year_of_birth)
			}
		);
	}
	return students;
}


void process_queries(const vector<Student>& students){
	int amount_of_data_queries;
	cin >> amount_of_data_queries;
	int student_record_number;
	string instruction;
	const vector<string> allowed_instructions = {"name", "date"};
	for (auto i = 0; i < amount_of_data_queries; i++){
		cin >> instruction >> student_record_number ;
		if (
				student_record_number < 1
				or student_record_number > students.size()
				or count(allowed_instructions.begin(), allowed_instructions.end(), instruction) == 0
		){
				cout << "bad request" << endl;
		} else {
			if (instruction == "name"){
				cout << students[student_record_number - 1].first_name;
				cout << " ";
				cout << students[student_record_number - 1].last_name;
				cout << endl;
			} else if (instruction == "date"){
				cout << students[student_record_number - 1].day_of_birth;
				cout << ".";
				cout << students[student_record_number - 1].month_of_birth;
				cout << ".";
				cout << students[student_record_number - 1].year_of_birth;
				cout << endl;
			}
		}
	}
}


int main(){
	const vector<Student>& students = collect_input();
	process_queries(students);
	return 0;
}
