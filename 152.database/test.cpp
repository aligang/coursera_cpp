#include <iostream>
#include <sstream>

#include "date.h"


using namespace std;


int main(){
    string cli_input;
    cli_input = "20180-2017-16";
    stringstream cli_stream(cli_input);
    cout << ParseDate(cli_stream) << endl;
    return 0;
};