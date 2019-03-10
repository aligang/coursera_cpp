int Factorial(int input_number){
	int factorial_value = 1;
	if (input_number > 1){
		for (int i = 2; i <= input_number; i++){
			factorial_value *= i;
		}
	}
	return factorial_value;
}
