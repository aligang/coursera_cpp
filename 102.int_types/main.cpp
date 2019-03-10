#include <iostream>
#include <cstdint>
#include <limits>
#include <vector>


using namespace std;


void PrintAvg(){
    vector<int> t{-4, -5, -6, -7};
    int sum = 0;
    for (auto x:t){
        sum +=x;
    }
    int avg = sum / static_cast<int>(t.size());
    cout << avg << endl;
}


int main(){
    cout << sizeof(int) << endl;
    cout << numeric_limits<int>::min() << " " << numeric_limits<int>::max() << endl;
    __int64_t zxc = 1234;
    cout << zxc << endl;

    unsigned int x = 5;
    int y = x;

    PrintAvg();
    return 0;
}