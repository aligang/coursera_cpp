#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;


void print_table_using_width(const vector<string>& names, const vector<double>& values, const int width){
	cout << setfill('.');
	cout << left;
	for (const auto& name:names){
		cout << setw(width) << name ;
	}
	cout << endl;
	cout << fixed;
	cout << setprecision(3);
	for (const auto& value:values){

		cout << setw(width);
		cout << value ;
	}
}


int main(){
	const int width = 10;
	const vector<string> names = {"a" ,"b" ,"c"};
	const vector<double> values = {1 ,0.5 ,0.00002};
	print_table_using_width(names, values, width);
}
