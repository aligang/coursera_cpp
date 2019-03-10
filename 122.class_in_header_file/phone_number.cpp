#include "phone_number.h"


#include <string>
#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <algorithm>


using namespace std;


bool contains_only_digits_and_letters(string& input_string){
    for (auto& letter:input_string){
        if (
            !(std::isdigit(letter))
                and
            !(std::isalpha(letter))
        ){
            return false;
        }
    }
    return true;
}


bool is_block_correct(string& element){
    if (element.size() == 0){
        return false;
    }
    if (
        (   
            !(std::isdigit(element[0]))
                and
            !(std::isalpha(element[0]))
        )
            or
        (
            !(std::isdigit(element[element.size() - 1]))
                and
            !(std::isalpha(element[element.size() - 1]))            
        )
    ){
            return false;
        }
    return true;
}


PhoneNumber::PhoneNumber(const string &international_number){
    stringstream string_stream(international_number);
    int dashes_amount = count(international_number.begin(), international_number.end(), '-');
    if (
        (international_number[0] != '+' )
            or
        (dashes_amount < 2)
    ){
        throw invalid_argument("wrong format: number should have 3 section devided by dashes" );
    }
    string_stream.ignore(1);
    getline(string_stream, country_code_, '-');
    getline(string_stream, city_code_, '-');
    string_stream >> local_number_;
    vector<string> number_parts = {country_code_, city_code_, local_number_}; 
    for (auto& number_part:number_parts){
        if ( 
            !is_block_correct(country_code_)
        ){
            throw invalid_argument("wrong format");    
        }        
    }
}


string PhoneNumber::GetCountryCode() const {
    return country_code_;
}


string PhoneNumber::GetCityCode() const{
    return city_code_;
}


string PhoneNumber::GetLocalNumber() const{
    return local_number_;
}


string PhoneNumber::GetInternationalNumber() const{
    return "+" + country_code_ + "-"  + city_code_ + "-" + local_number_;
}