#include <iostream>
#include <vector>
using namespace std;


void print_list_content(const vector<bool>& vector_to_print){
	int i = 1;
	for (auto element:vector_to_print){
		cout << "element #" << i << " = " << element << endl;
		i++;
	}

}


int main() {
	vector<bool> is_holiday(28, false);
	is_holiday[22] = true;
	print_list_content(is_holiday);
	cout << endl;
	is_holiday.resize(31);
	print_list_content(is_holiday);
	cout << endl;
	is_holiday.assign(31, false);
	print_list_content(is_holiday);
	cout << endl;
	is_holiday.clear();
	print_list_content(is_holiday);
}
