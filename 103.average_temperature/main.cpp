#include <iostream>
#include <vector>
#include <cstdint>


using namespace std;


int main(){
    __uint64_t amount_of_temperature_samples;
    __int64_t temperature_sample;
    __int64_t sum = 0;
    long double avg = 0;
    vector<__int64_t> temperature_samples = {};
    vector<__int64_t> output_samples = {};
    vector<__uint64_t> warm_days = {};
    cin >> amount_of_temperature_samples;
    for (int i = 0;  i < amount_of_temperature_samples; i++){
        cin >> temperature_sample;
        temperature_samples.push_back(temperature_sample);
        sum += temperature_sample;
    }
    avg = sum / static_cast<int>(temperature_samples.size());
    for (unsigned int i = 0;  i < temperature_samples.size(); i++){
        if (temperature_samples[i] > avg) {
            warm_days.push_back(i);
        }
    }

    for (auto& temperature_sample:temperature_samples){
        if (temperature_sample > avg) {
            output_samples.push_back(temperature_sample);
        }
    }
    cout << warm_days.size() << endl;
    for (auto& warm_day:warm_days){
        cout << warm_day << " " ;
    }
    cout << endl;
}
// -5 -4 -1 -2 -7