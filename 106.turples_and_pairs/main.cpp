#include <iostream>
#include <tuple>
#include <utility>


using namespace std;


int main(){

    tuple<const int&, const string&, const bool&> t(1, "2", true);
    cout << get<1>(t);
    return 0;
}