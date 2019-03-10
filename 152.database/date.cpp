#include "date.h"


Date::Date(const int& input_year, const int& input_month, const int& input_day)
    :year(input_year), month(input_month), day(input_day){};

int Date::GetYear() const{
    return year;
};

int Date::GetMonth() const{
    return month;
};

int Date::GetDay() const{
    return day;
};


std::ostream& operator << (std::ostream& output_stream, const Date& date){
    output_stream << date.GetYear() << "-" << date.GetMonth() << "-" << date.GetDay();
    return output_stream;
}

bool operator < (const Date& lhs, const Date& rhs){
	if (lhs.GetYear() < rhs.GetYear()){
        return true;
    } else if (lhs.GetYear() == rhs.GetYear()){
        if (lhs.GetMonth() < rhs.GetMonth()){
            return true;
		} else if (lhs.GetMonth() == rhs.GetMonth()){
			if (lhs.GetDay() < rhs.GetDay()){
				return true;
			}
		}
	}
	return false;
}


bool operator > (const Date& lhs, const Date& rhs){
	if (lhs.GetYear() > rhs.GetYear()){
        return true;
    } else if (lhs.GetYear() == rhs.GetYear()){
        if (lhs.GetMonth() > rhs.GetMonth()){
            return true;
		} else if (lhs.GetMonth() == rhs.GetMonth()){
			if (lhs.GetDay() > rhs.GetDay()){
				return true;
			}
		}
	}
	return false;
}


bool operator == (const Date& lhs, const Date& rhs){
    if ((lhs.GetYear() == rhs.GetYear()) && (lhs.GetMonth() == rhs.GetMonth()) && (lhs.GetDay() == rhs.GetDay())){
        return true;
    } else {
        return false;
    }
}

bool operator != (const Date& lhs, const Date& rhs){
    if ((lhs.GetYear() != rhs.GetYear()) || (lhs.GetMonth() != rhs.GetMonth()) || (lhs.GetDay() != rhs.GetDay())){
        return true;
    } else {
        return false;
    }
}


bool operator <= (const Date& lhs, const Date& rhs){
    if ((lhs < rhs) || (lhs == rhs)){
        return true;
    } else {
        return false;
    }
}


bool operator >= (const Date& lhs, const Date& rhs){
    if ((lhs > rhs) || (lhs == rhs)){
        return true;
    } else {
        return false;
    }
}


Date ParseDate(std::istream& sstream){ 
    int year;
    int month;
    int day;
    sstream >> year;
    sstream.ignore(1);
    sstream >> month;
    sstream.ignore(1);
    sstream >> day;
    Date date(year, month, day);
//    std::cout << typeid(date).name() << std::endl;
    return date;
};