template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    int length = distance(range_begin, range_end);
    if (length < 2){
        return;
    }
    vector<typename RandomIt::value_type> elements(
        range_begin,
        range_end
    );
    auto border_1 = next(elements.begin(), length/3);
    auto border_2 = next(elements.begin(), length*2/3);
    MergeSort(elements.begin(), border_1);
    MergeSort(border_1, border_2);
    MergeSort(border_2, elements.end());
    vector<typename RandomIt::value_type> temp;
    merge(
        elements.begin(), border_1,
        border_1, border_2,
        back_inserter(temp)
    );
    merge(
        temp.begin(), temp.end(),
        border_2, elements.end(),
        range_begin
    );
}