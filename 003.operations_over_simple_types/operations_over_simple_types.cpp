#include <iostream>
#include <string>
using namespace std;

int main(){
    int x, y;
    x = 5;
    y = 6;
    if (x < y) {
        cout << " y больше x " << "\n"; 
    } else if (x > y) {
        cout << " x больше y " << "\n";       
    } else {
        cout << " x и y равны " << "\n";        
    }
    string string1, string2;
    string1 = "aaa";
    string2 = "ab";
    if (string1 == string2) {
        cout << "string1 и string2 лексографически равны " << "\n";
    } else {
        cout << "string1 и string2 лексографически неравны " << "\n";
        if (string1 < string2) {
            cout << "string2 лексографически больше string1" << "\n"; 
        } else {
            cout << "string1 и string2 лексографически равны " << "\n";        
        }
    }
    return 0;
}
