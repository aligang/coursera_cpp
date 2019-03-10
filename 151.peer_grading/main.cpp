#include <iostream>
#include <string>
#include <vector>


using namespace std;


class Human{
    public:
        Human(const string& name, const string& occupation="Unemployed"): Name(name), Occupation(occupation){}
        virtual void Walk(const string& destination) const{
            IntroduceHuman() << " walks to: " << destination << endl;
        }

        ostream& IntroduceHuman() const {
            cout << Occupation << " " << Name;
            return cout;
        }

        const string Name;
        const string Occupation;
};


class Student:public Human{
    public:
        Student(const string& name, const string& favouriteSong): Human(name, "Student"), FavouriteSong(favouriteSong){}

        void Learn() const{
            IntroduceHuman() << " learns" << endl;
        }

        void SingSong () const{
            IntroduceHuman() << " sings a song: " << FavouriteSong << endl;
        }

        void Walk(const string& destination) const override{
            Human::Walk(destination);
            SingSong();
        }

        const string FavouriteSong;
    };


class Teacher:public Human{
    public:
        Teacher(const string& name, const string& subject):Human(name, "Teacher"), Subject(subject){
        }

        void Teach() {
            IntroduceHuman() << " teaches: " << Subject << endl;
        }

        const string Subject;
};


class Policeman:Human{
    public:
        Policeman(string name): Human(name, "Policeman"){}

        void Check(Human& h) {
            IntroduceHuman() << " checks " << h.Occupation << ". " <<  h.Occupation  << "'s name is: " << h.Name << endl;
        }

};


void VisitPlaces(const Human& h, const vector<string>& places) {
    for (auto& p:places) {
        h.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");
    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
