#include <iostream>
#include <iomanip>
#include <sstream>
#include <exception>


using namespace std;


struct Date{
	int day;
	int month;
	int year;

};


void check_symbol_and_skip(stringstream& input_string_stream){
	if (input_string_stream.peek() != '/'){
		stringstream error_message;
		error_message << "expected /, but has: " << char(input_string_stream.peek());
		throw runtime_error(error_message.str());
	}
	input_string_stream.ignore(1);
}


Date parse_date(const string& input_string){
	stringstream input_string_stream(input_string);
	Date date;
	input_string_stream >> date.year;
	check_symbol_and_skip(input_string_stream);
	input_string_stream >> date.month;
	check_symbol_and_skip(input_string_stream);
	input_string_stream >> date.day;
	return date;

}


int main(){
	string input_string = "2018/01/23";
	try {
		const Date& date = parse_date(input_string);
		cout << setw(2) << setfill('0') << date.day << ":"<< setw(2) << setfill('0') << date.month << ":" << date.year << endl;
	} catch (exception& ex) {
		cout << "shit happends" << endl;
		cout << ex.what() << endl;
	}
}
