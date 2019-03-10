#include <iostream>


using namespace std;


struct Day{
	int value;
	explicit Day(int new_value){
		value = new_value;
	}
};


struct Month{
	int value;
	explicit Month(int new_value){
		value = new_value;
	}
};


struct Year{
	int value;
	explicit Year(int new_value){
		value = new_value;
	}
};


struct Date{
	int day;
	int month;
	int year;

	Date(Day new_day, Month new_month, Year new_year){
		day = new_day.value;
		month = new_month.value;
		year = new_year.value;
	}
};






int main(){
	Date date = {Day{10}, Month(20), Year(13)};

	cout << date.day << ":" << date.month << ":" << date.year;
	return 0;
}
