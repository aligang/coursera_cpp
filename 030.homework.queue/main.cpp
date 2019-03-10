#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct QueueFillmentElement{
	string state;
	int numerical_parameter;
};


void collect_shell_input(int& number_of_input_operations, vector<QueueFillmentElement>& structs_of_shell_inputs){
	cin >> number_of_input_operations;
	for (auto i = 0; i < number_of_input_operations; i++){
		QueueFillmentElement single_cli_input;
		cin >> single_cli_input.state;
		if (single_cli_input.state != "WORRY_COUNT"){
			cin >> single_cli_input.numerical_parameter;
		}
		structs_of_shell_inputs.push_back(single_cli_input);
	}
}


void perform_opertions_over_queue(
		const vector<QueueFillmentElement>& struct_of_shell_inputs,
		vector<string>& queue
){
	int amount_of_worried_elements;
	for (auto operation:struct_of_shell_inputs){
		if (operation.state == "COME"){
			if (operation.numerical_parameter >= 0){
				for (int i = 0; i < operation.numerical_parameter; i++){
					queue.push_back("QUIET");
				}
			} else {
				queue.resize(queue.size() + operation.numerical_parameter);
			}
		} else if (operation.state == "QUIET"){
			queue[operation.numerical_parameter] = "QUIET";
		} else if (operation.state == "WORRY"){
			queue[operation.numerical_parameter] = "WORRY";
		} else if (operation.state == "WORRY_COUNT"){
			cout << count(begin(queue), end(queue), operation.state) << endl;
		}
	}
}


int main(){
	int number_of_input_operations;

	vector<QueueFillmentElement> structs_of_shell_inputs;
	vector<string> queue;
	collect_shell_input(number_of_input_operations, structs_of_shell_inputs);
	perform_opertions_over_queue(structs_of_shell_inputs, queue);

	return 0;
}
