void PrintStats(vector<Person> persons){
    int median_age = 0;
    median_age = ComputeMedianAge(
        persons.begin(), persons.end()
    );
    cout << "Median age = " << median_age << endl;
    median_age = ComputeMedianAge(
        persons.begin(), 
        partition(
            persons.begin(),
            persons.end(),
            [](Person& person){
                return person.gender == Gender::FEMALE;
            }
        )
    );
    cout << "Median age for females = " << median_age  << endl;
    median_age = ComputeMedianAge(
        persons.begin(), 
        partition(
            persons.begin(),
            persons.end(),
            [](Person& person){
                return person.gender == Gender::MALE;
            }
        )
    );
    cout << "Median age for males = " << median_age  << endl;
    median_age = ComputeMedianAge(
        persons.begin(), 
        partition(
            persons.begin(),
            persons.end(),
            [](Person& person){
                return (person.gender == Gender::FEMALE && person.is_employed == true);
            }
        )
    );
    cout << "Median age for employed females = " << median_age  << endl;
    median_age = ComputeMedianAge(
        persons.begin(), 
        partition(
            persons.begin(),
            persons.end(),
            [](Person& person){
                return (person.gender == Gender::FEMALE && person.is_employed == false);
            }
        )
    );
    cout << "Median age for unemployed females = " << median_age  << endl;
    median_age = ComputeMedianAge(
        persons.begin(), 
        partition(
            persons.begin(),
            persons.end(),
            [](Person& person){
                return (person.gender == Gender::MALE && person.is_employed == true);
            }
        )
    );
    cout << "Median age for employed males = " << median_age  << endl;
    median_age = ComputeMedianAge(
        persons.begin(), 
        partition(
            persons.begin(),
            persons.end(),
            [](Person& person){
                return (person.gender == Gender::MALE && person.is_employed == false);
            }
        )
    );
    cout << "Median age for unemployed males = " << median_age  << endl;
}