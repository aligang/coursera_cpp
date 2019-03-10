#include "print_vector_part.h"


#include <vector>


using namespace std;


int main(){
    vector<int> first_vector = {1, 2, -3, 4};
    vector<int> second_vector = {1, 2, 3, 4};
    PrintVectorPart(first_vector);
    PrintVectorPart(second_vector);
    return 0;
}