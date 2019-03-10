class SortedStrings {
public:
  void AddString(const string& s) {
    // добавить строку s в набор
	  strings.push_back(s);
	  sort_strings();
  }
  vector<string> GetSortedStrings() {
    // получить набор из всех добавленных строк в отсортированном порядке
	  return strings;
  }
private:
  vector<string> strings;
  void sort_strings(){
	  sort(strings.begin(), strings.end());
  }
};
