/*
 * main.cpp
 *
 *  Created on: 2 окт. 2018 г.
 *      Author: Алиса
 */

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int NOD(int a, int b) {
	a = abs(a);
	b = abs(b);
	while (a != 0 && b != 0) {
		if (a > b) {
			a = a % b; // a %= b;
		} else {
			b = b % a; // b %= a;
		}
	}
	return a + b;
}

class Rational {
    // Вставьте сюда реализацию класса Rational из первой части
public:
    Rational() {
    	p = 0;
    	q = 1;
    }

    Rational(int numerator, int denominator) {
    	int c = NOD(numerator, denominator);
    	//int nod = 0;
    	if (denominator < 0 && numerator > 0) {
    		p = -numerator / c;
    		q = -denominator / c;
    	} else {
    		if (denominator < 0 && numerator < 0) {
        		p = -numerator / c;
        		q = -denominator / c;
    		} else {
    			if (numerator == 0) {
    				p = numerator;
    				q = 1;
    			} else {
    				p = numerator / c;
    				q = denominator / c;
    			}
    		}
    	}
    }

    int Numerator() const {
    	return p;
    }

    int Denominator() const {
    	return q;
    }

private:
    int p;
    int q;
};

// Вставьте сюда реализацию operator == для класса Rational из второй части
bool operator==(const Rational& left, const Rational& right) {
	if (left.Numerator() == right.Numerator() && left.Denominator() == right.Denominator()) {
		return true;
	} else {
		return false;
	}
}

bool operator<(const Rational& left, const Rational& right) {
	return (left.Numerator() * right.Denominator() < left.Denominator() * right.Numerator());
}

bool operator>(const Rational& left, const Rational& right) {
	return (left.Numerator() * right.Denominator() > left.Denominator() * right.Numerator());
}

Rational operator+(const Rational& left, const Rational& right) {
	int numerator;
	int denominator;
	if (left.Denominator() == right.Denominator()) {
		numerator = left.Numerator() + right.Numerator();
		denominator = left.Denominator();
	} else {
		if (NOD(left.Denominator(), right.Denominator()) == 1) {
			numerator = left.Numerator() * right.Denominator() + right.Numerator() * left.Denominator();
			denominator = left.Denominator() * right.Denominator();
		} else {
			denominator = (left.Denominator() * right.Denominator()) / NOD(left.Denominator(), right.Denominator());
			numerator = left.Numerator() * (denominator / left.Denominator()) + right.Numerator() * (denominator / right.Denominator());
		}
	}
	return Rational(numerator, denominator);
}

Rational operator-(const Rational& left, const Rational& right) {
	int numerator;
	int denominator;
	if (left.Denominator() == right.Denominator()) {
		numerator = left.Numerator() - right.Numerator();
		denominator = left.Denominator();
	} else {
		if (NOD(left.Denominator(), right.Denominator()) == 1) {
			numerator = left.Numerator() * right.Denominator() - right.Numerator() * left.Denominator();
			denominator = left.Denominator() * right.Denominator();
		} else {
			denominator = (left.Denominator() * right.Denominator()) / NOD(left.Denominator(), right.Denominator());
			numerator = left.Numerator() * (denominator / left.Denominator()) - right.Numerator() * (denominator / right.Denominator());
		}
	}
	return Rational(numerator, denominator);
}

Rational operator*(const Rational& left, const Rational& right) {
	int numerator;
	int denominator;
	numerator = left.Numerator() * right.Numerator();
	denominator = left.Denominator() * right.Denominator();
	return Rational(numerator, denominator);
}

Rational operator/(const Rational& left, const Rational& right) {
	int numerator;
	int denominator;
	numerator = left.Numerator() * right.Denominator();
	denominator = left.Denominator() * right.Numerator();
	return Rational(numerator, denominator);
}

ostream& operator<<(ostream& stream, const Rational& r) {
	stream << r.Numerator() << '/' << r.Denominator();
	return stream;
}

istream& operator>> (istream& stream, Rational& r) {
	char delenie;
	int a, b;
	stream >> a >> delenie >> b;
	if (stream && delenie == '/') {
		r = { a, b };
	}
	return stream;
}

int main() {
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
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}


