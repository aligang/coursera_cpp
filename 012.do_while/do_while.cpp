#include <iostream>
#include <string>
using namespace std;

int main(){
	int a = 5;
	int b;
	do{
		cout << "Guess a the number [0..9]: ";
		cin >>  b;
	} while (a != b);
	cout << "you are right, it was " << b;
}
