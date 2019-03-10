#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <utility>
#include <limits>
#include <algorithm>


using namespace std;


int GreatestCommonDivisor(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return GreatestCommonDivisor(b, a % b);
  }
}


//#include "class_rational.cpp"


// поскольку дроби сокращены, достаточно сравнить числители и знаменатели
bool operator == (const Rational& lhs, const Rational& rhs) {
  return lhs.Numerator() == rhs.Numerator() &&
      lhs.Denominator() == rhs.Denominator();
}

// используем обычную формулу сложения дробей, основанную на приведении слагаемых к общему знаменателю
Rational operator + (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

// вычитание реализуем аналогично сложению
// дублирования кода можно было избежать, определив для класса Rational операцию унарного минуса: тогда разность lhs и rhs можно было бы вычислить           как lhs + (-rhs)
Rational operator - (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Numerator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
  // проверяем делитель на 0 (что равносильно проверке на 0 его числителя)
  if (rhs.Numerator() == 0) {
    throw domain_error("");
  }
  return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

istream& operator >> (istream& is, Rational& r) {
  int n, d;
  char c;
  is >> n >> c >> d;
  if (is && c == '/') {
    r = Rational(n, d);
  }
  return is;
}

ostream& operator << (ostream& os, const Rational& r) {
  return os << r.Numerator() << '/' << r.Denominator();
}

// чтобы сравнить lhs с rhs, сравним их разность с нулём, что равносильно сравнению с нулём числителя
bool operator < (const Rational& lhs, const Rational& rhs) {
  return (lhs - rhs).Numerator() < 0;
}


template <class A, class B>
ostream& operator<<(ostream& output_stream, const pair<A, B> output_pair){
	output_stream << output_pair.first << "/" << output_pair.second;
	return output_stream;
}

template <class T, class U>
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



void test_small_positive_numerator_1(){
    Rational test(1, 3);
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(1, 3);
    AssertEqual(
        test_answer, right_answer, 
        "test_small_positive_numerator failed"
    );
}

void test_small_positive_numerator_2(){
    Rational test(3, 1);
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(3, 1);
    AssertEqual(
        test_answer, right_answer, 
        "test_small_positive_numerator failed"
    );
}


void test_small_positive_denominator_1(){
    Rational test(1, 3);
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(1, 3);
    AssertEqual(
        test_answer, right_answer,  
        "test_small_positive_denominator failed"
    );
}

void test_small_positive_denominator_2(){
    Rational test(3, 1);
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(3, 1);
    AssertEqual(
        test_answer, right_answer,  
        "test_small_positive_denominator failed"
    );
}

void test_small_negative_numerator_1() {
    Rational test(-5, 10);
    const auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-1, 2);
    AssertEqual(test_answer, right_answer);
}


void test_small_negative_numerator_2() {
    Rational test(-10, 5);
    const auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-2, 1);
    AssertEqual(test_answer, right_answer);
}



void test_small_negative_denominator_1() {
    Rational test(5, -10);
    const auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-1, 2);
    AssertEqual(test_answer, right_answer);
}

void test_small_negative_denominator_2() {
    Rational test(10, -5);
    const auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-2, 1);
    AssertEqual(test_answer, right_answer);
}

void test_small_negative_numerator_and_denominator_1() {
    Rational test(-5, -10);
    const auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(1, 2);
    AssertEqual(test_answer, right_answer);
}

void test_small_negative_numerator_and_denominator_2() {
    Rational test(-10, -5);
    const auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(2, 1);
    AssertEqual(test_answer, right_answer);
}

void test_zero_input() {
    Rational test;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(0, 1);
    AssertEqual(test_answer, right_answer);
}


void test_null_nominator() {
    Rational test(0, 2);
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(0, 1);
    AssertEqual(test_answer, right_answer);
}


void test_large_positive_numerator() {
    Rational test(numeric_limits<int>::max(), 1);
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(2147483647, 1);
    AssertEqual(test_answer, right_answer);
}


void test_summarization_1() {
    Rational test1(1, 2);
    Rational test2(2, 2);
    Rational test = test1 + test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(3, 2);
    AssertEqual(test_answer, right_answer);
}

void test_summarization_2() {
    Rational test1(-1, 2);
    Rational test2(2, 2);
    Rational test = test1 + test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(1, 2);
    AssertEqual(test_answer, right_answer);
}


void test_summarization_3() {
    Rational test1(1, -2);
    Rational test2(2, 2);
    Rational test = test1 + test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(1, 2);
    AssertEqual(test_answer, right_answer);
}

void test_summarization_4() {
    Rational test1(-1, -2);
    Rational test2(2, 2);
    Rational test = test1 + test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(3, 2);
    AssertEqual(test_answer, right_answer);
}

void test_summarization_5() {
    Rational test1(1, 2);
    Rational test2(-2, 2);
    Rational test = test1 + test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-1, 2);
    AssertEqual(test_answer, right_answer);
}


void test_summarization_6() {
    Rational test1(1, 2);
    Rational test2(2, -2);
    Rational test = test1 + test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-1, 2);
    AssertEqual(test_answer, right_answer);
}


void test_summarization_7() {
    Rational test1(1, 2);
    Rational test2(-2, -2);
    Rational test = test1 + test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(3, 2);
    AssertEqual(test_answer, right_answer);
}


void test_multiplication_1() {
    Rational test1(1, 2);
    Rational test2(3, 2);
    Rational test = test1 * test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(3, 4);
    AssertEqual(test_answer, right_answer);
}


void test_multiplication_2() {
    Rational test1(-1, 2);
    Rational test2(3, 2);
    Rational test = test1 * test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-3, 4);
    AssertEqual(test_answer, right_answer);
}


void test_multiplication_3() {
    Rational test1(1, -2);
    Rational test2(3, 2);
    Rational test = test1 * test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-3, 4);
    AssertEqual(test_answer, right_answer);
}


void test_multiplication_4() {
    Rational test1(-1, -2);
    Rational test2(3, 2);
    Rational test = test1 * test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(3, 4);
    AssertEqual(test_answer, right_answer);
}



void test_multiplication_5() {
    Rational test1(1, 2);
    Rational test2(-3, 2);
    Rational test = test1 * test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-3, 4);
    AssertEqual(test_answer, right_answer);
}



void test_multiplication_6() {
    Rational test1(1, 2);
    Rational test2(3, -2);
    Rational test = test1 * test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-3, 4);
    AssertEqual(test_answer, right_answer);
}



void test_multiplication_7() {
    Rational test1(1, 2);
    Rational test2(-3, -2);
    Rational test = test1 * test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(3, 4);
    AssertEqual(test_answer, right_answer);
}


void test_substraction_1() {
    Rational test1(1, 2);
    Rational test2(6, 2);
    Rational test = test1 - test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-5, 2);
    AssertEqual(test_answer, right_answer);
}


void test_substraction_2() {
    Rational test1(-1, 2);
    Rational test2(6, 2);
    Rational test = test1 - test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-7, 2);
    AssertEqual(test_answer, right_answer);
}

void test_substraction_3() {
    Rational test1(1, -2);
    Rational test2(6, 2);
    Rational test = test1 - test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-7, 2);
    AssertEqual(test_answer, right_answer);
}

void test_substraction_4() {
    Rational test1(-1, -2);
    Rational test2(6, 2);
    Rational test = test1 - test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-5, 2);
    AssertEqual(test_answer, right_answer);
}


void test_substraction_5() {
    Rational test1(1, 2);
    Rational test2(-6, 2);
    Rational test = test1 - test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(7, 2);
    AssertEqual(test_answer, right_answer);
}



void test_substraction_6() {
    Rational test1(1, 2);
    Rational test2(6, -2);
    Rational test = test1 - test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(7, 2);
    AssertEqual(test_answer, right_answer);
}



void test_substraction_7() {
    Rational test1(1, 2);
    Rational test2(-6, -2);
    Rational test = test1 - test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-5, 2);
    AssertEqual(test_answer, right_answer);
}


void test_division_1() {
    Rational test1(1, 2);
    Rational test2(6, 2);
    Rational test = test1 / test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(1, 6);
    AssertEqual(test_answer, right_answer);
}


void test_division_2() {
    Rational test1(-1, 2);
    Rational test2(6, 2);
    Rational test = test1 / test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-1, 6);
    AssertEqual(test_answer, right_answer);
}


void test_division_3() {
    Rational test1(1, -2);
    Rational test2(6, 2);
    Rational test = test1 / test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-1, 6);
    AssertEqual(test_answer, right_answer);
}

void test_division_4() {
    Rational test1(-1, -2);
    Rational test2(6, 2);
    Rational test = test1 / test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(1, 6);
    AssertEqual(test_answer, right_answer);
}

void test_division_5() {
    Rational test1(1, 2);
    Rational test2(-6, 2);
    Rational test = test1 / test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-1, 6);
    AssertEqual(test_answer, right_answer);
}


void test_division_6() {
    Rational test1(1, 2);
    Rational test2(6, -2);
    Rational test = test1 / test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(-1, 6);
    AssertEqual(test_answer, right_answer);
}

void test_division_7() {
    Rational test1(1, 2);
    Rational test2(-6, -2);
    Rational test = test1 / test2;
    auto test_answer = make_pair(test.Numerator(), test.Denominator());
    auto right_answer = make_pair(1, 6);
    AssertEqual(test_answer, right_answer);
}


void test_comparison_1() {
    Rational test1(1, 2);
    Rational test2(6, 2);
    bool test = test1 < test2;
    auto test_answer = test;
    auto right_answer = true;
    AssertEqual(test_answer, right_answer);
}

void test_comparison_2() {
    Rational test1(-1, 2);
    Rational test2(6, 2);
    bool test = test1 < test2;
    auto test_answer = test;
    auto right_answer = true;
    AssertEqual(test_answer, right_answer);
}


void test_comparison_3() {
    Rational test1(1, -2);
    Rational test2(6, 2);
    bool test = test1 < test2;
    auto test_answer = test;
    auto right_answer = true;
    AssertEqual(test_answer, right_answer);
}


void test_comparison_4() {
    Rational test1(-1, -2);
    Rational test2(6, 2);
    bool test = test1 < test2;
    auto test_answer = test;
    auto right_answer = true;
    AssertEqual(test_answer, right_answer);
}


void test_comparison_5() {
    Rational test1(1, 2);
    Rational test2(-6, 2);
    bool test = test1 < test2;
    auto test_answer = test;
    auto right_answer = false;
    AssertEqual(test_answer, right_answer);
}


void test_comparison_6() {
    Rational test1(1, 2);
    Rational test2(6, -2);
    bool test = test1 < test2;
    auto test_answer = test;
    auto right_answer = false;
    AssertEqual(test_answer, right_answer);
}


void test_comparison_7() {
    Rational test1(1, 2);
    Rational test2(-6, -2);
    bool test = test1 < test2;
    auto test_answer = test;
    auto right_answer = true;
    AssertEqual(test_answer, right_answer);
}


void test_comparison_8() {
    Rational test1(-1, 2);
    Rational test2(-6, 2);
    bool test = test1 < test2;
    auto test_answer = test;
    auto right_answer = false;
    AssertEqual(test_answer, right_answer);
}


void test_comparison_9() {
    Rational test1(-1, 2);
    Rational test2(6, -2);
    bool test = test1 < test2;
    auto test_answer = test;
    auto right_answer = false;
    AssertEqual(test_answer, right_answer);
}

void test_comparison_10() {
    Rational test1(-1, 2);
    Rational test2(-6, -2);
    bool test = test1 < test2;
    auto test_answer = test;
    auto right_answer = true;
    AssertEqual(test_answer, right_answer);
}

void test_comparison_11() {
    Rational test1(1, -2);
    Rational test2(-6, 2);
    bool test = test1 < test2;
    auto test_answer = test;
    auto right_answer = false;
    AssertEqual(test_answer, right_answer);
}


void test_comparison_12() {
    Rational test1(1, -2);
    Rational test2(6, -2);
    bool test = test1 < test2;
    auto test_answer = test;
    auto right_answer = false;
    AssertEqual(test_answer, right_answer);
}

void test_comparison_13() {
    Rational test1(1, -2);
    Rational test2(-6, -2);
    bool test = test1 < test2;
    auto test_answer = test;
    auto right_answer = true;
    AssertEqual(test_answer, right_answer);
}

void test_comparison_14() {
    Rational test1(-1, -2);
    Rational test2(-6, 2);
    bool test = test1 < test2;
    auto test_answer = test;
    auto right_answer = false;
    AssertEqual(test_answer, right_answer);
}


void test_comparison_15() {
    Rational test1(-1, -2);
    Rational test2(6, -2);
    bool test = test1 < test2;
    auto test_answer = test;
    auto right_answer = false;
    AssertEqual(test_answer, right_answer);
}


void test_comparison_16() {
    Rational test1(-1, -2);
    Rational test2(-6, -2);
    bool test = test1 < test2;
    auto test_answer = test;
    auto right_answer = true;
    AssertEqual(test_answer, right_answer);
}

int main() {
    TestRunner runner;
    runner.RunTest(test_small_positive_numerator_1, "test_small_positive_numerator_1");
    runner.RunTest(test_small_positive_numerator_2, "test_small_positive_numerator_2");
    runner.RunTest(test_small_positive_denominator_1, "test_small_positive_denominator_1");
    runner.RunTest(test_small_positive_denominator_2, "test_small_positive_denominator_2");
    runner.RunTest(test_small_negative_numerator_1, "test_small_negative_numerator_1");
    runner.RunTest(test_small_negative_numerator_2, "test_small_negative_numerator_2");
    runner.RunTest(test_small_negative_denominator_1, "test_small_negative_denominator_1");
    runner.RunTest(test_small_negative_denominator_2, "test_small_negative_denominator_2");
    runner.RunTest(test_small_negative_numerator_and_denominator_1, "test_small_negative_numerator_denominator_1");
    runner.RunTest(test_small_negative_numerator_and_denominator_2, "test_small_negative_numerator_denominator_2");
    runner.RunTest(test_zero_input, "test_zero_input_rationals");
    runner.RunTest(test_null_nominator, "test_null_nominator");
    runner.RunTest(test_large_positive_numerator, "test_large_positive_numerator");
    runner.RunTest(test_summarization_1, "test_summarization_1");
    runner.RunTest(test_summarization_2, "test_summarization_2");
    runner.RunTest(test_summarization_3, "test_summarization_3");
    runner.RunTest(test_summarization_4, "test_summarization_4");
    runner.RunTest(test_summarization_5, "test_summarization_5");
    runner.RunTest(test_summarization_6, "test_summarization_6");
    runner.RunTest(test_summarization_7, "test_summarization_7");
    runner.RunTest(test_multiplication_1, "test_multiplication_1");
    runner.RunTest(test_multiplication_2, "test_multiplication_2");
    runner.RunTest(test_multiplication_3, "test_multiplication_3");
    runner.RunTest(test_multiplication_4, "test_multiplication_4");
    runner.RunTest(test_multiplication_5, "test_multiplication_5");
    runner.RunTest(test_multiplication_6, "test_multiplication_6");
    runner.RunTest(test_multiplication_7, "test_multiplication_7");
    runner.RunTest(test_substraction_1, "test_substraction_1");
    runner.RunTest(test_substraction_2, "test_substraction_2");
    runner.RunTest(test_substraction_3, "test_substraction_3");
    runner.RunTest(test_substraction_4, "test_substraction_4");
    runner.RunTest(test_substraction_5, "test_substraction_5");
    runner.RunTest(test_substraction_6, "test_substraction_6");
    runner.RunTest(test_substraction_7, "test_substraction_7");
    runner.RunTest(test_division_1, "test_division_1");
    runner.RunTest(test_division_2, "test_division_2");
    runner.RunTest(test_division_3, "test_division_3");
    runner.RunTest(test_division_4, "test_division_3");
    runner.RunTest(test_division_5, "test_division_5");
    runner.RunTest(test_division_6, "test_division_6");
    runner.RunTest(test_division_7, "test_division_7");
    runner.RunTest(test_comparison_1, "test_comparison_1");
    runner.RunTest(test_comparison_2, "test_comparison_2");
    runner.RunTest(test_comparison_3, "test_comparison_3");
    runner.RunTest(test_comparison_4, "test_comparison_4");
    runner.RunTest(test_comparison_5, "test_comparison_5");
    runner.RunTest(test_comparison_6, "test_comparison_6");
    runner.RunTest(test_comparison_7, "test_comparison_7");
    runner.RunTest(test_comparison_8, "test_comparison_8");
    runner.RunTest(test_comparison_9, "test_comparison_9");
    runner.RunTest(test_comparison_10, "test_comparison_10");
    runner.RunTest(test_comparison_11, "test_comparison_11");
    runner.RunTest(test_comparison_12, "test_comparison_12");
    runner.RunTest(test_comparison_13, "test_comparison_13");
    runner.RunTest(test_comparison_14, "test_comparison_14");
    runner.RunTest(test_comparison_15, "test_comparison_15");
    runner.RunTest(test_comparison_16, "test_comparison_16");
}