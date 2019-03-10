#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class ReversibleString{
public:
	ReversibleString() {}
	ReversibleString(const string& input_string){
		data_string = input_string;
	}
	void Reverse(){
		reverse(data_string.begin(), data_string.end());
	}
	string ToString() const{
		return data_string;
	}
private:
	string data_string;
};
