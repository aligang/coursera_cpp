#include "print_vector_part.h"


#include <algorithm>
#include <iostream>


using namespace std;


void PrintVectorPart(const vector<int>& numbers){
    vector<int>::const_iterator first_negative_element = find_if(
        numbers.begin(), numbers.end(), [](const int& number){
            return number < 0;
        }
    );
    while (first_negative_element != numbers.begin()){
        first_negative_element--;
        cout << *first_negative_element << " ";
    }
    cout << endl;
}
