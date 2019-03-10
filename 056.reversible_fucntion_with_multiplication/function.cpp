#include <string>
#include <algorithm>
#include <vector>
#include <iostream>



class FunctionPart {
public:
  FunctionPart(char new_operation, double new_value) {
    operation = new_operation;
    value = new_value;
  }
  double Apply(double source_value) const {
    double output;
    if (operation == '+') {
    	output = source_value + value;
    } else if (operation == '*'){
    	if (source_value != 0 and value != 0){
    		output = source_value * value;
    	}
    } else if (operation == '/'){
    	if (source_value != 0 and value != 0){
    		output = source_value / value;
    	}
    } else {
    	output = source_value - value;
    }
    return output;
  }
  void Invert() {
    if (operation == '+') {
      operation = '-';
    } else if (operation == '-') {
      operation = '+';
    } else if (operation == '*') {
        operation = '/';
    } else if (operation == '/') {
        operation = '*';
    }
  }
private:
  char operation;
  double value;
};


class Function {
public:
  void AddPart(char operation, double value) {
    parts.push_back({operation, value});
  }
  double Apply(double value) const {
    for (const FunctionPart& part : parts) {
      value = part.Apply(value);
    }
    return value;
  }
  void Invert() {
    for (FunctionPart& part : parts) {
      part.Invert();
    }
    reverse(begin(parts), end(parts));
  }
private:
  vector<FunctionPart> parts;
};
