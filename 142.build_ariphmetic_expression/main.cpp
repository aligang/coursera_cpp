#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


vector<string> collect_cli_input(){
    int amount_of_iterations = 0;
    vector<string> operations(0);
    string operation;
    cin >> amount_of_iterations;
    cin.ignore(1);
    for (auto i = 0; i < amount_of_iterations; i++){
        getline(cin, operation);
        operations.push_back(operation);
    }
    return operations;
}


void perform_operations(string& equation, const vector<string>& operations){
    int amount_of_brackets = 0;
    if (operations.size() > 1){
        for (auto it = operations.begin(); it != prev(operations.end()); it++){
            if (
                ((*it)[0]  == '+' or (*it)[0]  == '-')
                    and
                ((*(next(it)))[0]  == '*' or (*(next(it)))[0]  == '/')
            ){
                amount_of_brackets++;
            }
        }
    }
    for (auto i = 0; i < amount_of_brackets; i++){
        cout << "(";
    }
    cout << equation;
    for (auto it = operations.begin(); it != operations.end(); it++){    
        if (
            it != operations.begin()
        ){
            if (
                ((*it)[0] == '*' or (*it)[0] == '/')
                    and
                ((*(prev(it)))[0]  == '+' or (*(prev(it)))[0]  == '-')
            ){
                cout << ")";
            }
        }        
        cout << " "<< *it;
    }
    cout << endl;
}


int main(){
    string equation = "";
    cin >> equation;
    const vector<string>&  operations = collect_cli_input();
    perform_operations(equation, operations);
    return 0;

}