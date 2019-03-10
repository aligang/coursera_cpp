#include <iostream>
#include <string>
#include <vector>
using namespace std;


// определяет, является ли строка s палиндромом
bool IsPalindrom(string input_string){
	int possibe_iterations_amount = input_string.size();
	if (possibe_iterations_amount > 1){
		for (int i = 0; i < possibe_iterations_amount / 2; i++){
			if (input_string[i] != input_string[possibe_iterations_amount - 1 - i] ){
				return false;
			}
		}
	}
	return true;
}

vector<string> PalindromFilter(vector<string> words, int min_length) {
  vector<string> result;
  // перебираем все элементы вектора words
  for (auto s : words) {
    // если требуеые условия выполняются, добавляем s к ответу
    if (s.size() >= min_length && IsPalindrom(s)) {
      result.push_back(s);
    }
  }
  return result;
}


int main(){
//	vector<string> words = {"aba", "abababb ", "abcdcba",  "abcdedcba"};
	vector<string> words = {"a"};
	int minLength = 1;
	vector<string> filtered_words = PalindromFilter(words, minLength);
	for (auto filtered_word:filtered_words){
		cout << filtered_word << ", ";
	}
}

