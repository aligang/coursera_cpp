#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;


enum class Gender {
  FEMALE,
  MALE
};


struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};


template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}


void PrintStats(vector<Person> persons){
    int median_age = 0;
    median_age = ComputeMedianAge(
        persons.begin(), persons.end()
    );
    cout << "Median age = " << median_age << endl;
    median_age = ComputeMedianAge(
        persons.begin(), 
        partition(
            persons.begin(),
            persons.end(),
            [](Person& person){
                return person.gender == Gender::FEMALE;
            }
        )
    );
    cout << "Median age for females = " << median_age  << endl;
    median_age = ComputeMedianAge(
        persons.begin(), 
        partition(
            persons.begin(),
            persons.end(),
            [](Person& person){
                return person.gender == Gender::MALE;
            }
        )
    );
    cout << "Median age for males = " << median_age  << endl;
    median_age = ComputeMedianAge(
        persons.begin(), 
        partition(
            persons.begin(),
            persons.end(),
            [](Person& person){
                return (person.gender == Gender::FEMALE && person.is_employed == true);
            }
        )
    );
    cout << "Median age for employed females = " << median_age  << endl;
    median_age = ComputeMedianAge(
        persons.begin(), 
        partition(
            persons.begin(),
            persons.end(),
            [](Person& person){
                return (person.gender == Gender::FEMALE && person.is_employed == false);
            }
        )
    );
    cout << "Median age for unemployed females = " << median_age  << endl;
    median_age = ComputeMedianAge(
        persons.begin(), 
        partition(
            persons.begin(),
            persons.end(),
            [](Person& person){
                return (person.gender == Gender::MALE && person.is_employed == true);
            }
        )
    );
    cout << "Median age for employed males = " << median_age  << endl;
    median_age = ComputeMedianAge(
        persons.begin(), 
        partition(
            persons.begin(),
            persons.end(),
            [](Person& person){
                return (person.gender == Gender::MALE && person.is_employed == false);
            }
        )
    );
    cout << "Median age for unemployed males = " << median_age  << endl;
}


int main() {
  vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}