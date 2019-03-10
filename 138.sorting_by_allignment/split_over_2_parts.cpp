template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    if (distance(range_begin, range_end) < 2){
        return;
    }
    auto it = next(
        range_begin,
        distance(range_begin,range_end)/2
    );
    vector<typename RandomIt::value_type> first_elements(
        range_begin,
        it
    );
    vector<typename RandomIt::value_type> last_elements(
        it,
        range_end
    );
    MergeSort(first_elements.begin(), first_elements.end());
    MergeSort(last_elements.begin(),  last_elements.end());
    merge(
        first_elements.begin(), first_elements.end(),
        last_elements.begin(),  last_elements.end(),
        range_begin
    );
}