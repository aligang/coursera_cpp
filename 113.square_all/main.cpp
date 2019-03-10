#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <utility>


using namespace std;


// Предварительное объявление шаблонных функций
template <typename input_value, typename output_value>
output_value operator * (input_value& x, input_value& y) ;
template <typename first_value, typename second_value>
pair<first_value, second_value> operator * (pair<first_value, second_value>& pair_1, pair<first_value, second_value>& pair_2);
template <typename key, typename value>
map<key, value> operator * (map<key, value>& x_map, map<key, value>& y_map);
template <typename value>
vector<value> operator * (vector<value>& vector_1, vector<value>& vector_2);

// Объявляем шаблонные функции
template <typename input_value, typename output_value>
output_value operator * (input_value& x, input_value& y) {
	return x*y;
}


template <typename first_value, typename second_value>
pair<first_value, second_value> operator * (pair<first_value, second_value>& pair_1, pair<first_value, second_value>& pair_2) {
	pair<first_value, second_value> result;
	result = make_pair(
		pair_1.first*pair_2.first,
		pair_1.second*pair_2.second
	);
	return result;
}


template <typename key, typename value>
map<key, value> operator * (map<key, value>& x_map, map<key, value>& y_map) {
	map<key, value> result;
	for (auto& element:x_map){
		result[element.first] = element.second * y_map[element.first];
	}
	return result;
}


template <typename value>
vector<value> operator * (vector<value>& vector_1, vector<value>& vector_2) {
	vector<value> result;
	for (size_t i = 0; i < vector_1.size(); i++ ){
		result.push_back(vector_1[i] * vector_2[i]);
	}
	return result;
}


template <typename T>
T Sqr(T& x) {
	return x*x;
}



int main(){
	// Пример вызова функции
	vector<int> v = {1, 2, 3};
	//vector<int> v = {2, 12, 36}; 
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int> > map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	Sqr(map_of_pairs);
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}

	//pair<int, double> k;
	//pair<int, double> m = make_pair(2, 2.5);
	//k = Sqr(m);
	//cout << k.first << " " << k.second << endl; 
}
