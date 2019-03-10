#include "rectangle.h"
    

#include <iostream>


using namespace std;


int main(){
    Rectangle rectangle(2, 3);
    cout << rectangle.GetArea() << endl;
    cout << rectangle.GetPerimeter() << endl;
    cout << rectangle.GetWidth() << endl;
    cout << rectangle.GetHeight() << endl;
    return 0;
}