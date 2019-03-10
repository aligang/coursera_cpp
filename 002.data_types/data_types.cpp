#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    int a;
    double pi;
    bool logical_value;
    char letter;
    a = 5;
    pi = 3.1415926;
    logical_value = true;
    letter = 'X';
    cout << "Значение целого числа = ";
    cout << a;
    cout << "\n";
    cout << "Значение дробного числа = ";
    cout << pi;
    cout << "\n";
    cout << "Значение булевой величины = ";
    cout << logical_value;
    cout << "\n";
    cout << "Буковка -> ";
    cout << letter;
    cout << "\n";

    string basic_string = "какая-то строка";
    cout << "строчечка -> ";
    cout << basic_string;
    cout << "\n";

    vector<int> nums = {1, 2, 3};
    cout << "длина вектора -> ";
 //   cout << nums;
    cout << " составляет ";
    cout <<  nums.size(); 
    cout << " элементов ";   
    cout << "\n";

    map<string, int> names_to_values{{"zero", 0},};
    names_to_values["first"] = 1;
    names_to_values["second"] = 2;
    cout << "second это " << names_to_values["second"] << "\n";

    struct Donkey{
        string size;
        string color;
    };
    vector<Donkey> donkeys;
    donkeys.push_back({"большой", "белый"});
    donkeys.push_back({"малый", "серый"});
    cout << "Второй ослик был " << donkeys[1].color << "\n";    
    return 0;
}
