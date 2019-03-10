#include <iostream>
#include "functions.cpp"
using namespace std;


//int Factorial(int input_number){
//	int factorial_value = 1;
//	if (input_number > 1){
//		for (int i = 2; i <= input_number; i++){
//			factorial_value *= i;
//		}
//	}
//	return factorial_value;
//}


int main(){
	int input_number;
	cin >> input_number;
	cout << Factorial(input_number);
	return 0;
}
