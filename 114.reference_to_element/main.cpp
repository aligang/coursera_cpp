#include <iostream>
#include <map>
#include <exception>

using namespace std;


template <typename map_key, typename map_value>
map_value& GetRefStrict(map<map_key, map_value>& input_map, const map_key& input_key) {
    if (input_map.count(input_key) == 1){
        return input_map[input_key]; 
    } else {
        throw runtime_error("");
    }
}


int main(){
    map<int, string> m = { {0, "value"} };
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
}