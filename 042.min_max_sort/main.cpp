#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void print_vector(vector<int>& vector_to_print){
	for (auto& element:vector_to_print){
		cout << element << " ";
	}
	cout << endl;
}

bool greater_than_zero(int& x){
	if (x > 0){
		return true;
	} else {
	return false;
	}
}

int main(){
	int a = 2;
	int b = 3;
	string s1 = "abc";
	string s2 = "bac";
	cout << min(a,b)<< endl;
	cout << max(s1,s2)<< endl;
	vector<int> v = {
		10, 2, 33, -4, 5, 6
	};
	sort(v.begin(), v.end());
	print_vector(v);
	cout << count(begin(v),end(v), 5) << endl;
	cout << count_if(begin(v),end(v), greater_than_zero) << endl;
	int zero_value = 0;
	cout << count_if(begin(v),end(v), [zero_value](int x){
			if (x > zero_value){
				return true;
			} else {
				return false;
			}
		}
	) << endl;

}
