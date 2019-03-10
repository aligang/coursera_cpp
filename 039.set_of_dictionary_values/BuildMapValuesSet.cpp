set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> set_of_values;
	for (auto& pair:m){
		set_of_values.insert(pair.second);
	}
	return set_of_values;
}
