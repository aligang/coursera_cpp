#include <iostream>
#include <fstream>
#include <string>


using namespace std;


void copy_file_content(const string& source_path, const string& destination_path){
	string single_input_string;
	ifstream input(source_path);
	if (input){
		ofstream output(destination_path);
		while (getline(input, single_input_string)){
			output << single_input_string << endl;
		}
	}
}


int main(){
	const string source_path = "input.txt";
	const string destination_path = "output.txt";
	copy_file_content(source_path, destination_path);
}
