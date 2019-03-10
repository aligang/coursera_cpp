#include <iostream>
#include <string>
using namespace std;

int main(){
    string first_name, last_name;
    int x, y;
    cout << "Introduce yourself, please: \n";
    cin >> first_name >> last_name;
    cout << "Hello, " << first_name << " " << last_name << "\n";
    cout << "Input two numbers to multiply, \n";
    cout << "first one: ";
    cin >> x;
    cout << "second one: ";
    cin >> y;
    cout << "Result is: " << x*y << "\n";
    cout << "bye " << first_name << "\n";
}