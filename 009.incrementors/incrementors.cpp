#include <iostream>
#include <string>
using namespace std;

int main(){
	int a = 10;
	int b = 7;
	double aa = 10;

	cout << "a/b = " << a/b << endl;
	cout << "aa/b = " << aa/b << endl;
	a += 3;
	cout << "a = " << a << endl;
	a -= 3;
	cout << "a = " << a << endl;
	a *= 3;
	cout << "a = " << a << endl;
	a /= 3;
	cout << "a = " << a << endl;

    int d = a++;
    int e = ++a;
	cout << "d = " << d << endl;
	cout << "e = " << e << endl;
}
