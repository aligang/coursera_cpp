#include <vector>
#include <set>
#include <iostream>
#include <algorithm>


using namespace std;


template <typename T>
void print_container_contents(const T& container){
    for(auto it=container.begin(); it != container.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


template <typename T>
void RemoveDuplicates(vector<T>& elements){
    sort(
        elements.begin(), elements.end()
    );
    auto it = unique(
        elements.begin(), elements.end()
    );
    elements.erase(it, elements.end());
}


int main(){
    vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
    RemoveDuplicates(v1);
    for (int x : v1) {
        cout << x << " ";
    }
    cout << endl;
  
    vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
    RemoveDuplicates(v2);
    for (const string& s : v2) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}