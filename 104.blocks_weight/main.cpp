#include <iostream>
#include <cstdint>
#include <limits>


using namespace std;


int calculate_volume(){
    return 0;
}

int main(){
//    cout << sizeof(unsigned int) << endl;
//    cout << numeric_limits<int>::min() << " " << numeric_limits<int>::max() << endl;
    __uint32_t amount_of_blocks = 0;
    __uint32_t density = 0;
    __uint32_t length = 0;
    __uint32_t width = 0;
    __uint32_t height = 0;
    __uint64_t total_mass = 0;
    cin >> amount_of_blocks >> density;
    for (__uint32_t i = 0; i < amount_of_blocks; i++){
        cin  >> length >> width >> height;
        total_mass += static_cast<__uint64_t>(length)*width*height*density;
    }
    cout << total_mass << endl;
}