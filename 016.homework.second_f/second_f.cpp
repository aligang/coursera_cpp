#include<iostream>
using namespace std;

int main(){
	int f_register = -2;
	string input_string;
	cin >> input_string;
	for (int i = 0; i < input_string.size(); i++){
		if (input_string[i] == 'f'){
			if (f_register == -2){
				f_register = -1;
			} else if (f_register == -1){
				f_register = i;
			}
		}
	}
	cout << f_register;
	return 0;
}
