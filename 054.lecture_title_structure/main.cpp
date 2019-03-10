#include <string>


using namespace std;


struct Specialization{
	string value;
	explicit Specialization(const string& specialization_name){
		value = specialization_name;
	}
};


struct Course{
	string value;
	explicit Course(const string& course_name){
		value = course_name;
	}
};


struct Week{
	string value;
	explicit Week(const string& course_duration){
		value = course_duration;
	}
};


struct LectureTitle{
	string specialization;
	string course;
	string week;
	LectureTitle(Specialization specialization_name, Course course_name, Week week_name){
		specialization = specialization_name.value;
		course = course_name.value;
		week = week_name.value;

	}
};


int main(){
	LectureTitle title(
	    Specialization("C++"),
	    Course("White belt"),
	    Week("4th")
	);
}
