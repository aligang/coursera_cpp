#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a,b,c;
	int input_value_threshold = 1000000;
	cin >> a;
	cin >> b;
	if (abs(a) > input_value_threshold or abs(a) > input_value_threshold){
		cout << "\n";
		cout << "input conditions are not met:" << "\n";
		cout << "one of values exceed threshold of: " << input_value_threshold << "\n";
		cout << "\n" << "Please rerun program and provide valid input data";
	} else {
		c = a + b;
		cout  << c;
	}
	return 0;
}
