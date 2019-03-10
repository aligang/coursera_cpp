#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;

//	a = abs(a);
//	b = abs(b);
//	if (a == 0 || b == 0 ){
//		a = max(a, b);
//	} else {
//		while ( a != b){
//			if (a > b){
//				a -= b;
//			} else {
//				b -= a;
//			}
//		}
//	}

	while (a > 0 and b > 0){
		if (a > b){
			a %= b;
		} else {
			b %= a;
		}
	}
	cout << (a + b);
}
