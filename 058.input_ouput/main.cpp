#include <iostream>
#include <fstream>
#include <string>


using namespace std;


void read_file_content(const string& path){
	string input_string;
	ifstream input(path);
	if (input){
		cout << "reading file ..." << endl << endl;
		while (getline(input, input_string)){
			cout << input_string << endl;
		}
	} else {
		cout << "file_is_not_accessible" << endl;
	}
}


int main(){
	const string path = "test_file.txt";
	{
		ofstream output(path);
		output << "string#1" << endl << "string#2" << endl;
		read_file_content(path);
	}
	{
		ofstream output(path);
		output << "string#1" << endl << "string#2" << endl;
		read_file_content(path);
	}
	{
		ofstream output(path, ios::app);
		output << "string#3" << endl << "string#4" << endl;
		read_file_content(path);
	}
}
