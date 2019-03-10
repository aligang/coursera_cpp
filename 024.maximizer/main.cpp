#include <iostream>
#include <string>
using namespace std;


void UpdateIfGreater(int& first, int& second){
	if (first > second){
		second = first;
		cout << first << " " << second ;
	}
}


int main(){
	int a = 1;
	int b = 2;
	UpdateIfGreater(a, b);

}
