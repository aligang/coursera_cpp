#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};



bool IsPalindrom(const string& input_string){
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


void empty_string_test(){
    AssertEqual(IsPalindrom(""), true, "empty string");
}


void single_char(){
    AssertEqual(IsPalindrom("1"), true, "single char");
}

void single_char_2(){
    AssertEqual(IsPalindrom(" "), true, "single char 2");
}

void single_char_3(){
    AssertEqual(IsPalindrom("A"), true, "single char 3");
}

void single_char_4(){
    AssertEqual(IsPalindrom("a"), true, "single char 4");
}

void many_numbers(){
    AssertEqual(IsPalindrom("121"), true, "many numbers");
}

void many_chars(){
    AssertEqual(IsPalindrom("abcdcba"), true, "many chars");
}

void many_chars_2(){
    AssertEqual(IsPalindrom("abcddcba"), true, "many chars 2");
}

void many_chars_3(){
    AssertEqual(IsPalindrom("abcdcba "), false, "many chars 3");
}

void many_chars_4(){
    AssertEqual(IsPalindrom("abcddcb "), false, "many chars 4");
}

void many_chars_5(){
    AssertEqual(IsPalindrom(" abcdcba "), true, "many chars 5");
}


void many_chars_6(){
    AssertEqual(IsPalindrom(" abcddcba "), true, "many chars 5");
}

void many_chars_7(){
    AssertEqual(IsPalindrom("abc cba"), true, "many chars 7");
}
void many_chars_8(){
    AssertEqual(IsPalindrom("abc  cba"), true, "many chars 8");
}

void many_chars_9(){
    AssertEqual(IsPalindrom("abcd cba"), false, "many chars 9");
}

void many_chars_10(){
    AssertEqual(IsPalindrom("ab dd ba"), true, "many chars 10");
}

void many_chars_11(){
    AssertEqual(IsPalindrom(" abc cba"), false, "many chars 11");
}

void many_chars_21(){
    AssertEqual(IsPalindrom(" abc abc"), false, "many chars 11");
}

void many_chars_22(){
    AssertEqual(IsPalindrom("abcabc"), false, "many chars 12");
}


void many_chars_last_is_capital(){
    AssertEqual(IsPalindrom("abcdcbA"), false, "many_chars_last_is_capital");
}

void many_chars_last_is_capital_1(){
    AssertEqual(IsPalindrom("abcddcbA"), false, "many_chars_last_is_capital 1");
}

void many_chars_center_is_capital_1(){
    AssertEqual(IsPalindrom("abcDcba"), true, "many_chars_center_is_capital 1");
}

void many_chars_center_is_capital_2(){
    AssertEqual(IsPalindrom("abcDdcba"), false, "many_chars_center_is_capital 1");
}


int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
    runner.RunTest(empty_string_test, "empty_string_test");
    runner.RunTest(single_char, "single_char");
    runner.RunTest(single_char_2, "single_char_2");
    runner.RunTest(single_char_3, "single_char_3");
    runner.RunTest(single_char_4, "single_char_4");
    runner.RunTest(many_numbers, "many_numbers");
    runner.RunTest(many_chars, "many_chars");
    runner.RunTest(many_chars_2, "many_chars_2");
    runner.RunTest(many_chars_3, "many_chars_3");
    runner.RunTest(many_chars_4, "many_chars_4");
    runner.RunTest(many_chars_5, "many_chars_5");
    runner.RunTest(many_chars_6, "many_chars_6");
    runner.RunTest(many_chars_7, "many_chars_7");
    runner.RunTest(many_chars_8, "many_chars_8");    
    runner.RunTest(many_chars_9, "many_chars_9");
    runner.RunTest(many_chars_10, "many_chars_10");
    runner.RunTest(many_chars_11, "many_chars_11");
    runner.RunTest(many_chars_21, "many_chars_21");
    runner.RunTest(many_chars_22, "many_chars_22");
    runner.RunTest(many_chars_last_is_capital, "many_chars_last_is_capital");
    runner.RunTest(many_chars_last_is_capital_1, "many_chars_last_is_capital 1");
    runner.RunTest(many_chars_center_is_capital_1, "many_chars_last_is_capital 1");
    runner.RunTest(many_chars_center_is_capital_2, "many_chars_last_is_capital 2");
  return 0;
}