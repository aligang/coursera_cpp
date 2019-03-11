#pragma once


#include <iostream>
#include <sstream>

//using namespace std;


class Date {
    private:
        const int year;
        const int month;
        const int day;
    public:
        Date(const int& input_year, const int& input_month, const int& input_day);
        int GetYear() const;
        int GetMonth() const;
        int GetDay() const;

};

bool operator < (const Date& lhs, const Date& rhs);
bool operator > (const Date& lhs, const Date& rhs);
bool operator == (const Date& lhs, const Date& rhs);
bool operator != (const Date& lhs, const Date& rhs);
bool operator <= (const Date& lhs, const Date& rhs);
bool operator >= (const Date& lhs, const Date& rhs);

std::ostream& operator << (std::ostream& output_stream, const Date& date);

Date ParseDate(std::istream& sstream);