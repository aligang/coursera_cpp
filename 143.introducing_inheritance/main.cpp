#include <iostream>
#include <string>

using namespace std;


struct Fruit{
    int hp = 0;
    string type = "fruit";
};


struct Apple:public Fruit{
    Apple(){
        hp = 10;
        type = "apple";
    }
};


struct Orange:public Fruit{
    Orange(){
        hp = 5;
        type = "orange";
    }
};


class Animal{
    public:
        string type = "animal";
        void eat(const Fruit& some_fruit) const{
            cout << type << " ate " << some_fruit.type << " with " << some_fruit.hp << " healhpoints" << endl;
        }
};


class Cat:public Animal{
    public:
        Cat(){
            type = "cat";
        }
        void Meow() const{
            cout << "Cat Meaws " << endl;
        }
};


class Dog:public Animal{
    public:
        Dog(){
            type = "dog";
        };
};


void doMeal(const Animal& beast, const Fruit& food){
    beast.eat(food);
}


int main(){
    Apple apple;
    Orange orange;
    Cat cat;
    Dog dog;
    cat.eat(apple);
    cat.Meow();
    dog.eat(orange);
    doMeal(cat, orange);
    return 0;
}