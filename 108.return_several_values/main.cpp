#include <vector>
#include <map>
#include <string>
#include <set>
#include <tuple>
#include <iostream>


using namespace std;


class Cities{
	public:
		tuple<bool, string> FindCountry(const string& city) const {
			if (cities_to_countries.count(city) == 1) {
				return {true, cities_to_countries.at(city)};
			} else {
				return {false, "No cities found"};
			}
		}
	private:
		map<string, string> cities_to_countries;
		set<string> ambigous_cities;

};


int main(){
	Cities cities;
	auto [answer, comment] = cities. FindCountry("Volga");
	cout << answer << " " << comment;
	return 0;
}
