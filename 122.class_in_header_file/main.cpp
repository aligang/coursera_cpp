#include "phone_number.h"


#include <iostream>
#include <string>

 
using namespace std;


int main(){
    string phone_number_string;;
    cin >> phone_number_string;
    PhoneNumber phone_number = PhoneNumber(phone_number_string);
    cout << phone_number.GetCountryCode() << endl;
    cout << phone_number.GetCityCode() << endl;
    cout << phone_number.GetLocalNumber() << endl;
    cout << phone_number.GetInternationalNumber() << endl;
}