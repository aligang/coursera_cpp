#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>


using namespace std;


template <typename T>
void print_container_contents(const T& container){
    for(auto it=container.begin(); it != container.end(); it++){
        cout << *it << ", ";
    }
    cout << endl;
}


int main(){
    {
        vector<string> langs = {"Python", "C++", "C", "C#", "Java"};
        vector<string> c_langs = {"bla-bla"};
        auto it = copy_if(
            langs.begin(), langs.end(), 
            back_inserter(c_langs),
            [](string& lang){
                return lang[0] == 'C';
            }
        ); 
        print_container_contents(
            c_langs
        );
    }
    {
        vector<string> langs = {"Python", "C++", "C", "C#", "Java"};
        vector<string> c_langs = {"bla-bla"};
        auto it = copy_if(
            langs.begin(), langs.end(), 
            inserter(c_langs, next(c_langs.begin())),
            [](string& lang){
                return lang[0] == 'C';
            }
        ); 
        print_container_contents(
            c_langs
        );
    }
    {
        set<int> a = {1, 2, 3};
        set<int> b = {2, 3, 4, 5};
        set<int> c;
        auto it = set_intersection(
            a.begin(), a.end(),
            b.begin(), b.end(),
            inserter(c, c.begin())
        ); 
        print_container_contents(
            c
        );
    }
}