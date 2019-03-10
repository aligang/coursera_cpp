#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool Contains(vector<string> words, string word){
	for (auto w:words){
		if (w == word){
			return true;
		}
	}
	return false;
}
void PrintContent(vector<string> words){
	for (auto word:words){
		cout << word << " ";
	}
}
int main(){
	vector<string> words = {"one", "two", "three", "four"};
	string word = "one";
	cout << Contains(words, word) << endl;
	PrintContent(words);
	return 0;
}
