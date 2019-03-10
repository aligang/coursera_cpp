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


int main(){
    {
        vector<string> langs = {"Python", "C++", "C", "C#", "Java"};
        auto result = remove_if(
            langs.begin(), langs.end(), [](string& lang){
                return lang[0] == 'C';
            }
        );
        langs.erase(result, langs.end());
        print_container_contents(langs);
    }
    {
        vector<string> langs = {"Python", "C++", "C++", "C++", "Java", "C++"};
        auto result = unique(
            langs.begin(), langs.end()
        );
        langs.erase(result, langs.end());
        print_container_contents(langs);
    }
    {
        vector<string> langs = {"Python", "C++", "C++", "C++", "Java", "C++"};
        sort(
            langs.begin(), langs.end()
        );
        auto result = unique(
            langs.begin(), langs.end()
        );
        langs.erase(result, langs.end());
        print_container_contents(langs);
    }
    {
        vector<string> langs = {"Python", "C++", "C++", "C++", "Java", "C++"};
        auto result = min_element(
            langs.begin(), langs.end()
        );
        cout << *result << endl;
    }
    {
        vector<string> langs = {"Python", "C++", "C++", "C++", "Java", "C++"};
        auto result = max_element(
            langs.begin(), langs.end()
        );
        cout << *result << endl;
    }
    {
        vector<string> langs = {"Python", "C++", "C++", "C++", "Java", "C++"};
        auto result = minmax_element(
            langs.begin(), langs.end()
        );
        cout << *result.first << " " <<*result.second << endl;
    }
    {
        set<string> langs = {"Python", "C++", "C++", "C++", "Java", "C++"};
        auto result = all_of(
            langs.begin(), langs.end(),[](const string& lang){
                return (lang[0] >= 'A' && lang[0] <= 'Z');
            }
        );
        cout << result << endl;
    }
}