#include <iostream>
#include <string>
using namespace std;

int main(){
	string t = "hey";
	string s = t;
	t += " you";
	cout << s << endl;
	cout << t << endl;
	return 0;
}
