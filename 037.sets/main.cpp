#include <set>
#include <iostream>
#include <vector>
#include <string>


using namespace std;


void PrintSet(const set<string>& some_set){
	cout << "size is " << some_set.size() << endl;
	for (auto& element:some_set){
		cout << element << endl;
	}
}


int main(){
	set<string> famous_person;
	famous_person.insert("Madonna");
	famous_person.insert("Maradonna");
	PrintSet(famous_person);
	famous_person.insert("Me");
	PrintSet(famous_person);
	famous_person.erase("Me");
	PrintSet(famous_person);
	set<string> months = {"Jan", "Feb", "March", "March"};
	set<string> another_months = {"Feb", "March", "Jan","Jan",};
	cout << (months == another_months);
	vector<string> chars = {"a", "b", "c", "d", "a", "b"};
	set<string> unique_chars(begin(chars), end(chars));
//	void print_set_directly_from_main(){
//		for (auto& element:unique_chars){
//			cout << element << endl;
//		}
//	}
	PrintSet(unique_chars);
	return 0;
}
