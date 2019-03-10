#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <exception>
using namespace std;


long biggest_common_devider(const long& a, const long& b){
	long c = a;
	long d = b;
	while (c > 0 and d > 0){
		if (c > d){
			c %= d;
		} else {
			d %= c;
		}
	}
	return c + d;
}


long least_common_multiple(const long& a,const long& b){
	return a/biggest_common_devider(a, b)*b;
}


class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
    	p = 0;
    	q = 1;
    };

    Rational(const long& numerator, const long& denominator) {
        // Реализуйте конструктор
    	if(denominator == 0){
    		stringstream error_message;
    		error_message << "Invalid argument";
    		throw invalid_argument(error_message.str());
    	} else if (
    		(numerator > 0 and denominator > 0)
				or
			(numerator < 0 and denominator < 0)
    	){
    		p = abs(numerator) / biggest_common_devider(abs(numerator), abs(denominator));
    		q = abs(denominator) / biggest_common_devider(abs(numerator), abs(denominator));
    	} else if (
    		(numerator > 0 and denominator < 0)
    			or
			(numerator < 0 and denominator > 0)
    	){
    		p = -1*abs(numerator) / biggest_common_devider(abs(numerator), abs(denominator));
    		q = abs(denominator) / biggest_common_devider(abs(numerator), abs(denominator));
    	} else if (
    		(numerator == 0)
				or
			(denominator != 0)
		){
        	p = 0;
        	q = 1;
    	} else if (denominator != 0){
            p = 0;
            q = 1;
        }
    };

    long Numerator() const {
        // Реализуйте этот метод
    	return p;
    }

    long Denominator() const {
        // Реализуйте этот метод
    	return q;
    }

private:
    // Добавьте поля
    long p;
    long q;

};


Rational operator+(const Rational& lhs, const Rational& rhs){
	const long& p1 =lhs.Numerator();
	const long& q1 =lhs.Denominator();
	const long& p2 =rhs.Numerator();
	const long& q2 =rhs.Denominator();
	const long& lcm = least_common_multiple(q1, q2);

	const Rational& result = Rational(
		p1*lcm/q1+p2*lcm/q2,
		lcm
	);
	return result;
}


Rational operator-(const Rational& lhs, const Rational& rhs){
	const long& p1 =lhs.Numerator();
	const long& q1 =lhs.Denominator();
	const long& p2 =rhs.Numerator();
	const long& q2 =rhs.Denominator();
	const long& lcm = least_common_multiple(q1, q2);

	const Rational& result = Rational(
		p1*lcm/q1-p2*lcm/q2,
		lcm
	);
	return result;
}


Rational operator*(const Rational& lhs, const Rational& rhs){
	const long& p1 =lhs.Numerator();
	const long& q1 =lhs.Denominator();
	const long& p2 =rhs.Numerator();
	const long& q2 =rhs.Denominator();
	const Rational& result = Rational(
		p1*p2,
		q1*q2
	);
	return result;
}


Rational operator/(const Rational& lhs, const Rational& rhs){
	const long& p1 =lhs.Numerator();
	const long& q1 =lhs.Denominator();
	const long& p2 =rhs.Numerator();
	if (p2 == 0){
		stringstream error_message;
		error_message << "Division by zero";
		throw domain_error(error_message.str());

	}
	const long& q2 =rhs.Denominator();
	const Rational& result = Rational(
		p1*q2,
		q1*p2
	);
	return result;
}


bool operator==(const Rational& lhs, const Rational& rhs){
	const long& p1 =lhs.Numerator();
	const long& q1 =lhs.Denominator();
	const long& p2 =rhs.Numerator();
	const long& q2 =rhs.Denominator();
	bool result = false;
	if ((p1 == p2) and (q1 == q2)){
		result = true;
	}
	return result;
}


bool operator<(const Rational& lhs, const Rational& rhs){
	const long& p1 =lhs.Numerator();
	const long& q1 =lhs.Denominator();
	const long& p2 =rhs.Numerator();
	const long& q2 =rhs.Denominator();
	bool result = false;
	if (p1*q2 < p2*q1){
		result = true;
	}
	return result;
}


ostream& operator<<(ostream& output_stream, const Rational& rational){
	output_stream << rational.Numerator() << "/" << rational.Denominator();
	return output_stream;
}


istream& operator>>(istream& input_stream, Rational& rational){
	long p, q;
	string input_buffer;
	if (!input_stream.eof()){
		input_stream >> p;
		input_stream.ignore(1);
		input_stream >> q;
		rational = Rational(p, q);
	} else {
		input_stream.setstate(std::ios::eofbit);
	}
	return input_stream;
}


struct Input_elements{
	Rational first_element;
	Rational second_element;
	char action;
};


Input_elements collect_cli_input(){
	Input_elements cli_input;
	cin >> cli_input.first_element;
	cin >> cli_input.action;
	cin >> cli_input.second_element;
	return cli_input;
}


void process_cli_input(const Input_elements& cli_input){
	if (cli_input.action == '+') {
		cout << cli_input.first_element + cli_input.second_element << endl;
	} else if (cli_input.action == '-') {
		cout << cli_input.first_element - cli_input.second_element << endl;
	} else if (cli_input.action == '*') {
		cout << cli_input.first_element * cli_input.second_element << endl;
	} else if (cli_input.action == '/') {
		cout << cli_input.first_element / cli_input.second_element << endl;
	}
}


int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "первый набор тестов пройден" << endl;

    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }


//    cout << "второй набор тестов пройден" << endl;

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

//    cout << "третий набор тестов пройден" << endl;

    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }


    cout << "четвёртый набор тестов пройден" << endl;

    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, long> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument& ex) {
    }
    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }


    try {
        const Input_elements& cli_input = collect_cli_input();
    	process_cli_input(cli_input);
    } catch (invalid_argument& ia) {
    	cout << ia.what();
    } catch (domain_error& de) {
    	cout << de.what();
    }



    return 0;
}
