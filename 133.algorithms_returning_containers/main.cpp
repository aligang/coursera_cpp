#include <vector>
#include <set>
#include <iostream>
#include <algorithm>


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
        auto it = partition(
            langs.begin(), langs.end(), [](string& lang){
                return lang[0] == 'C';
            }
        ); 
        print_container_contents(
            vector<int>(
                {1, 2, 3, 4, 5}
            )
        );
        print_container_contents(
            vector<string>(
                {langs.begin(), it}
            )
        );
        print_container_contents(
            vector<string>(
                {it, langs.end()}
            )
        );
    }
    {
        vector<string> langs = {"Python", "C++", "C", "C#", "Java"};
        vector<string> c_langs(langs.size());
        auto it = copy_if(
            langs.begin(), langs.end(), c_langs.begin(),[](string& lang){
                return lang[0] == 'C';
            }
        ); 
        print_container_contents(
            vector<string>(
                {c_langs.begin(), it}
            )
        );
    }
    {
        set<int> a = {1, 2, 3};
        set<int> b = {2, 3, 4, 5};
        vector<int> c(
            min(
                a.size(),
                b.size()
            )
        );
        auto it = set_intersection(
            a.begin(), a.end(),
            b.begin(), b.end(),
            c.begin()
        ); 
        print_container_contents(
            vector<int>(
                {c.begin(), it}
            )
        );
    }
}