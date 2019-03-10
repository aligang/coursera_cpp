#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string first_string, second_string, third_string, minimal_string;
	cin >> first_string >> second_string >> third_string;
	if (first_string <= second_string && first_string <= third_string){
		cout << first_string;
	} else if (second_string < first_string && second_string <= third_string) {
		cout << second_string;
	} else {
		cout << third_string;
	}
	return 0;
}
