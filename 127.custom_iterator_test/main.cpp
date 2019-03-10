#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main(){
    int some_int = 10;
    vector<int> some_vector = {1, 2, 3, 4, 5, 6};
    int* int_ptr =& some_int;
    cout <<  int_ptr << endl;
    cout <<  *int_ptr << endl;
    vector<int>* vector_ptr =& some_vector; 
    vector<int>::iterator vector_iter = some_vector.begin();
    cout << *vector_iter << endl;
    vector_iter++;
    cout << *vector_iter << endl;
    vector_iter--;
    cout << *vector_iter << endl;
    int_ptr++;
    cout << *int_ptr << endl;
}