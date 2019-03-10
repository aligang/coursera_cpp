#include <iostream>
#include <fstream>
#include <string>


using namespace std;


int main(){
	string input_string;
	{
		ifstream input("test.txt");
		if (input){
			while (getline(input,input_string)){
				cout << input_string << endl;

			}
			cout << "done" << endl;
		} else {
			cout << "Can not read file" << endl;
		}
	}
	{
		ifstream input("date.txt");
		string year, month, day;
		if (input){
			getline(input, year, '-');
			getline(input, month, '-');
			getline(input, day, '-');
			cout << year << "   " << month << "   " << day << endl;
		}
	}
	{
		ifstream input("date.txt");
		int year, month, day;
		if (input){
			input >> year;
			input.ignore(1);
			input >> month;
			input.ignore(1);
			input >> day;
			cout << year << "   " << month << "   " << day << endl;
		}
	}
}
