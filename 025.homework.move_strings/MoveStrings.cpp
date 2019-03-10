void MoveStrings(vector<string>& source,vector<string>& destination){
	for (auto element:source){
		destination.push_back(element);
	}
	source.clear();
}
