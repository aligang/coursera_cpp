#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


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


int main(){
	  ReversibleString s("live");
	  s.Reverse();
	  cout << s.ToString() << endl;

	  s.Reverse();
	  const ReversibleString& s_ref = s;
	  string tmp = s_ref.ToString();
	  cout << tmp << endl;

//ReversibleString empty;
//	  cout << '"' << empty.ToString() << '"' << endl;
	return 0;
}
