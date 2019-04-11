#include "Value.h"

void Integer::Print() const {
	std::cout << IntegerNumber;
}

void Double::Print() const {
	std::cout << DoubleNumber;
}


void Complex::Print() const {
	std::cout << RealPart << '+' << ImaginaryPart << 'i';
}
