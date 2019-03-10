#include <vector>
#include <set>
#include <iostream>
#include <algorithm>


using namespace std;


template <typename T>
void print_container_contents(const T& container){
    for(auto it=container.begin(); it != container.end(); it++){
        if (it != container.begin()){
            cout << " ";
        }
        cout << *it;
    }
    cout << endl;
}


void number_shuffler(int& max_number){
    vector<int> numbers(0);
    for (auto i=1; i <= max_number; i++){
        numbers.push_back(i);
    }
    sort(numbers.rbegin(), numbers.rend());
    do {
        print_container_contents(numbers);
    } while(
        prev_permutation(
            numbers.begin(), numbers.end()
        )
    );
}


int main(){
    int max_number;
    cin >> max_number;
    number_shuffler(max_number);
    return 0;
}