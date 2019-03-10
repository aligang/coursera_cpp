#include <iostream>
#include <stdlib.h>

using namespace std;

int main (){
	int x, y;
	cin >> x >> y;
	if (y == 0) {
		cout << "Impossible";
	} else {
		cout << x/y;
	}
}
