#include <iostream>
using namespace std;

int main(){
// маленький комент, чтобы показать как работает счетчик через цикл for
    for (int i = 0; i < 10; i++){
        cout << i << " ";
    }
    cout << "\n";
/* 
 * большой комент,
 * чтобы показать как работает счетчик через цикл while */
    int k = 0;
    while (k <= 10){
        cout << k << " ";
        k++;
    }
    cout << "\n";
}