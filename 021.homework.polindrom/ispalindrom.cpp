bool IsPalindrom(string input_string){
	int possibe_iterations_amount = input_string.size();
	if (possibe_iterations_amount > 1){
		for (int i = 0; i < possibe_iterations_amount / 2; i++){
			if (input_string[i] != input_string[possibe_iterations_amount - 1 - i] ){
				return false;
			}
		}
	}
	return true;
}
