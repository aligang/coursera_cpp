#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>


using namespace std;


int main(){
	ifstream input("input.txt");
	if (input){
		string single_input_string;
		cout << fixed;
		cout << setprecision(3);
		while (getline(input, single_input_string)){
			cout << atof(single_input_string.c_str()) << endl;
		}
	}
}
