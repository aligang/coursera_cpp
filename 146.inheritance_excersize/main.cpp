#include <iostream>


using namespace std;


class Animal {
public:
    Animal(const string& name): Name(name){}
    // ваш код
    const string Name;
};


class Dog:public Animal {
public:
    // ваш код
    Dog(const string& name):Animal(name){
        const string type = "dog";
    };
    
    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};


int main(){
    Dog dog("Lucky");
    dog.Bark();
    return 0;
}