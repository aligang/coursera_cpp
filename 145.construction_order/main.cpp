#include <iostream>
#include <string>


using namespace std;


struct Log{
    Log(string name):n(name){
        cout << " + " << n << endl;
    }

    ~Log(){
        cout << " - " << n << endl;
    }
    string n;
};


struct Fruit{
    Fruit(const string& t):l(t + " (Fruit)"){};
    const Log l;
};


struct Apple:public Fruit{
    Apple(const string& t):Fruit(t), l(t){};
    const Log l;
};


int main(){
    Apple a1("a1");
    Apple a2("a2");
    return 0;
}