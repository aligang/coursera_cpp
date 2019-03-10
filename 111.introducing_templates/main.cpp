#include <iostream>
#include <utility>
#include <map>
#include <sstream>


using namespace std;


template <typename T>
T sqr(const T& x){
	return x*x;
}


template <typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& p1,const pair<First, Second>& p2){
	return {
		p1.first*p2.first,
		p1.second*p2.second
	};
}

int main(){
	auto p = make_pair(2, 35);
	auto result = sqr(p);
	cout << result.first << endl;
	cout << result.second << endl;
}
