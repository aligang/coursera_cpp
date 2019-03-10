#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>


using namespace std;


struct Lang{
    string name;
    int age;
};

using string_iterator = vector<string>::iterator;
using pair_iterator = map<string, int>::iterator;


void print_strings_range(string_iterator range_begin, string_iterator range_end){
    for (string_iterator it = range_begin; it != range_end; it++){
        cout << *it << " ";
    }
    cout << endl;
}


void print_pair_range(pair_iterator range_begin, pair_iterator range_end){
    for (pair_iterator it = range_begin; it != range_end; it++){
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
}


template <class generic_iterator>
void print_generic_range(generic_iterator range_begin,generic_iterator  range_end){
    for (generic_iterator it = range_begin; it != range_end; it++){
        cout << *it << " ";
    }
    cout << endl;
}


int main(){
    {
        vector<string> langs = {"Python", "C++", "C", "C#"};
        auto result = find_if(
            langs.begin(), langs.end(),[](const string& lang){
                return lang.front() == 'C';
            }
        );
        cout << *result << endl;
        string& variable = *result;
        cout << variable << endl;
        variable = "D--";
    }
    {
        vector<Lang> langs = {
            {"Python", 26},
            {"C++", 34}, 
            {"C", 45},
            {"C#", 22}
        };
        auto result = find_if(
            langs.begin(), end(langs),[](const Lang& lang){
                return lang.name.front() == 'E';
            }
        );
        if (result == end(langs)){
            cout << "Nothing Found" << endl;
        } else {
            cout << (*result).age << endl;  
            cout << result->age << endl;
        }

    }
    {
        vector<string> langs = {"Python", "C++", "C", "C#"};
        print_strings_range(langs.begin(), langs.end());
    }    
    {
        vector<string> langs = {"Python", "C++", "C", "C#"};
        print_generic_range(langs.begin(), langs.end());
    }
    {   
        vector<string> langs = {"Python", "C++", "C", "C#"};
        auto result = find_if(
            langs.begin(), end(langs), [](const string& lang){
                return *(lang.begin()) == 'C';
            }
        );
        print_generic_range(langs.begin(), result);
        print_generic_range(result, langs.end());
    }
    {   
        set<string> langs = {"Python", "C++", "C", "C#"};
        auto result = find_if(
            langs.begin(), end(langs), [](const string& lang){
                return *(lang.begin()) == 'C';
            }
        );
        print_generic_range(langs.begin(), result);
        print_generic_range(result, langs.end());
    }
    {   
        map<string, int> langs = {
            {"Python", 26},
            {"C++", 34}, 
            {"C", 45},
            {"C#", 22}
        };
        auto result = find_if(
            langs.begin(), end(langs), [](const pair<string, int>& lang){
                return *(lang.first.begin()) == 'P';
            }
        );
        cout << "first_part_of_dict" << endl;
        print_pair_range(langs.begin(), result);
        cout << "second_part_of_dict" << endl;
        print_pair_range(result, langs.end());
    }
    return 0;
}