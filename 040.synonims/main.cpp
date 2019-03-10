#include <string>
#include <set>
#include <iostream>
#include <map>


using namespace std;


void add_synonims(set<set<string>>& synonims, map<string,set<set<string>>>& word_appearences, const string& synonim_1, const string& synonim_2){
	synonims.insert({synonim_1, synonim_2});
	word_appearences[synonim_1].insert({synonim_1, synonim_2});
	word_appearences[synonim_2].insert({synonim_1, synonim_2});
}


void count_synonims(map<string,set<set<string>>>& word_appearences, const string& word){
	cout << word_appearences[word].size() << endl;
}


void check_synonims(const set<set<string>>& synonims,const set<string>& words){
	if (synonims.count(words) == 1){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}


int main(){
	int amount_of_iterations;
	string operation, synonim_1, synonim_2;
	set<set<string>> synonims;
	map<string,set<set<string>>> word_appearences;
	cin >> amount_of_iterations;
	for(int iteration = 0; iteration < amount_of_iterations; iteration++){
		cin >> operation;
		if (operation == "ADD"){
			cin >> synonim_1 >> synonim_2;
			add_synonims(synonims, word_appearences, synonim_1, synonim_2);
		} else if (operation == "COUNT") {
			cin >> synonim_1;
			count_synonims(word_appearences, synonim_1);
		} else if (operation == "CHECK"){
			cin >> synonim_1 >> synonim_2;
			check_synonims(synonims, {synonim_1, synonim_2});
		}
	}
}
