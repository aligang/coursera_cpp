#include <iostream>
#include <string>
using namespace std;

int main(){
	double initial_cost, small_discount_threshold, big_discount_threshold,	small_discount_rate, big_discount_rate, final_price;
	cin >> initial_cost >> small_discount_threshold >> big_discount_threshold >> small_discount_rate >> big_discount_rate;
	if (initial_cost <= small_discount_threshold) {
		final_price = initial_cost;
	} else if (initial_cost > small_discount_threshold && initial_cost <= big_discount_threshold) {
		final_price = initial_cost*(1-small_discount_rate/100);
	} else {
		final_price = initial_cost*(1-big_discount_rate/100);
	}
	cout << final_price;
	return 0;
}
