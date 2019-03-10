#include <vector>
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


int main(){
    vector<string> langs = {"Python", "C++", "C", "C#", "Java"};
    vector<string>::const_iterator it;
    print_container_contents(langs);
    it = (
        find(langs.begin(), langs.end(), "C")
    );
//    langs.erase(it);
    langs.erase(it, langs.end());
    print_container_contents(
        langs
    );
    langs.insert(langs.end(), "Ruby");
    print_container_contents(
        langs
    );
    langs.insert(langs.end(), {"C", "C#", "C++"});
    print_container_contents(
        langs
    );
    langs.insert(langs.end(), 2, "Pascal");
    print_container_contents(
        langs
    );
}