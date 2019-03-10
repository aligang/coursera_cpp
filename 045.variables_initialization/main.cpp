#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


void Print(int x){
	string output = (x % 2 == 0) ? "even":"odd";
	cout << output << endl;
}


int main(){
	Print(5);
}
