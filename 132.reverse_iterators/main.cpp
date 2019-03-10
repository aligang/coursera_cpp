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
void print_container_contents_in_reverse_order(const T& container){
    for(auto it=container.rbegin(); it != container.rend(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


int main(){
    {
        vector<string> langs = {"Python", "C++", "C", "C#", "Java"};
        print_container_contents_in_reverse_order(langs);
    }
    {
        vector<string> langs = {"Python", "C++", "C", "C#", "Java"};
        auto it = langs.rbegin();
        it += 2;
        cout << *it << endl;
    }
    {
        vector<string> langs = {"Python", "C++", "C", "C#", "Java"};        
        auto it = find_if(
            langs.rbegin(), langs.rend(), [](string& lang){
                return lang[0] == 'C';
        });
        cout << *it << endl;        
    }
    {
        vector<string> langs = {"Python", "C++", "C", "C#", "Java"};        
        sort(
            langs.rbegin(), langs.rend()
        );
        print_container_contents(langs);        
    }
}