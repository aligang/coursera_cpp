#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string blablastring = "blablabla!!!";
    cout << "iteration over " << blablastring << "\n";
    for (char element:blablastring){
        cout << element << "\n";
    }  

    vector<int> list_of_integers = {1, 2, 3, 4, 5, 1, 2, 3, 1};
    cout << "iteration over list of integers" << "\n";
    for  (int element:list_of_integers){
        cout << element << "\n";        
    }
    int amount_of_matches = 0;
    int number_to_match = 1;
    for (auto element:list_of_integers){
        if (element == number_to_match){
            amount_of_matches += 1 ;
        }
    }
    cout << "элемент " << number_to_match << " встречается " << amount_of_matches << " раз \n" ; 

    amount_of_matches = 0;
    cout << "элемент " << number_to_match << " встречается " << amount_of_matches << " раз \n" ;
    amount_of_matches = count(begin(list_of_integers), end(list_of_integers), number_to_match);
    cout << "элемент " << number_to_match << " встречается " << amount_of_matches << " раз \n" ;
    sort(begin(list_of_integers), end(list_of_integers));
    cout << "отсортированный список выглядит так: \n";
    for  (int element:list_of_integers){
        cout << element << "\n";        
    }    
    return 0;
} 