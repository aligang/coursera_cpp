#include <iostream>
#include <tuple>
#include <string>

using namespace std;

struct Date{
    int year;
    string month;
    int day;
};


auto decompose_date(const Date& date){
    return tie(date.year, date.month, date.day);
}

bool operator<(const Date& lhs, const Date& rhs){
    return decompose_date(lhs) < decompose_date(rhs);
}

int main(){
cout << (Date{2018, "2", 1} < Date{2018, "3", 1}) << endl;
    return 0;
}
