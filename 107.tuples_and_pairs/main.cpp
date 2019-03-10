#include <iostream>
#include <vector>
#include <tuple>
#include <utility>


using namespace std;


int main(){

    tuple<const int, const string, const bool> t(1, "2", true);
    cout << get<1>(t) << endl;
    pair <int, string> p{1, "abc"};
    auto pp = make_pair(1, "abc");
    cout << p.second << endl;
    return 0;
}
