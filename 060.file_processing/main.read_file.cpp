#include <iostream>
#include <fstream>
#include <string>


using namespace std;


void read_file_content(const string& path){
	string single_input_string;
	ifstream input(path);
	if (input){
		while (getline(input, single_input_string)){
			cout << single_input_string << endl;
		}
	}
}


int main(){
	const string path = "input.txt";
	read_file_content(path);
}
