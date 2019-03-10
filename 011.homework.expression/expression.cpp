#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	double a,b,c,d,x1,x2;
	cin >> a >> b >> c;
	d = b*b - 4*a*c;
/*
 * calculating expression roots
 */
	if (a == 0){
		if (b != 0){
			x1 = -c/b;
			cout << x1;
		}
	}
	else if (d > 0){
		x1 = (-b + sqrt(d))/(2*a);
		x2 = (-b - sqrt(d))/(2*a);
		cout << x1 << " " << x2;
	}
	else if (d == 0) {
		x1 = -b/(2*a);
		cout << x1;
	}
	return 0;
}
