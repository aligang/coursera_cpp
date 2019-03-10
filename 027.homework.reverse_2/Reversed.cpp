vector<int> Reversed(const vector<int>& v){
	vector<int> reversed_vector;
	for (auto number:v){
		reversed_vector.insert(reversed_vector.begin(), number);
	}
	return reversed_vector;
}
