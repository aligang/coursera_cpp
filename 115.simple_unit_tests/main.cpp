#include <iostream>
#include <cassert>


using namespace std;


int sum(int& x, int& y){
    return x+y;
}

void test(){
    int a = 2;
    int b = 3; 
    assert(sum(a, b) == 4);
}

int main(){
    test();
//    int a = 2;
//    int b = 3;
//    int s = sum(a, b);
//    cout << s << endl;

}