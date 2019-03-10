#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <math.h>
#include <sstream>
#include <iomanip>


using namespace std;


class Figure{
    public:
        virtual string Name() = 0;
        virtual double Area() = 0;
        virtual double Perimeter() = 0;
    private:
        //const string _name;
};


class Circle:public Figure{
    public:
        Circle(const double& r):Figure(){
            _radius = r;
            _name = "CIRCLE";
        }
        double Area() override{
            return 3.14 * _radius * _radius;
        }
        double Perimeter() override{
            return 2 * 3.14 * _radius;
        }
        string Name() override{
            return _name;
        }
    private:
        double _radius;
        string _name;
};


class Rect:public Figure{
    public:
        Rect(const double& w, const double& h):Figure(){
            _width = w;
            _height = h;
            _name = "RECT";
        }
        double Area() override{
            return _width * _height;
        }
        double Perimeter() override{
            return 2 * (_width + _height);
        }
        string Name() override{
            return _name;
        }
    private:
        double _width;
        double _height;
        string _name;
};


class Triangle:public Figure{
    public:
        Triangle(double& A, double& B, double& C):Figure(){
            _a = A;
            _b = B;
            _c = C;
            _name = "TRIANGLE";
        }
        double Area() override{
            double _p = (_a + _b + _c)/2;
            return sqrt(_p * (_p - _a) * (_p - _b) * (_p - _c));
        }
        double Perimeter() override{
            return _a + _b + _c;
        }
        string Name() override{
            return _name;
        }
    private:
        double _a;
        double _b;
        double _c;
        string _name;
};


shared_ptr<Figure> CreateFigure(istringstream& is){
    shared_ptr<Figure> figure_ptr;
    string figure_name;
    is >> figure_name;
    if (figure_name == "CIRCLE"){
        double radius;
        is >> radius;
        figure_ptr = make_shared<Circle>(radius);
    } else if (figure_name == "RECT"){
        double width, height;
        is >> width >> height;
        figure_ptr = make_shared<Rect>(width, height);
    } else if (figure_name == "TRIANGLE"){
        double a, b, c;
        is >> a >> b >> c;
        figure_ptr = make_shared<Triangle>(a, b, c);
    }
    return figure_ptr;
}


int main() {
  vector<shared_ptr<Figure> > figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);
    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}