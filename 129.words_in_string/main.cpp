#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;
using char_iterator = string::const_iterator;

vector<string> SplitIntoWords(const string& s){
    vector<string> words;
    string::const_iterator string_begin = s.begin();
    char_iterator string_end = s.end();
    char_iterator word_begin = s.begin();
    char_iterator word_end = s.begin();
    while (word_end != string_end){
        word_end = find_if(word_begin, string_end, [](const char& letter){
            return letter == ' ';
        });
        words.push_back(
            {word_begin, word_end}
        );
        word_begin = word_end;
        if (word_end != string_end){
            word_begin++;
        }
    }
    return words;
}


int main(){
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}
