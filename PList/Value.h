#pragma once

#include <iostream>

class Value {
public:
	virtual void Print() const = 0;
};

class Integer : public Value {
public:
	Integer(const int& integer_number) : IntegerNumber(integer_number) {}
	void Print() const override;
private:
	const int IntegerNumber;
};

class Double : public Value {
public:
	Double(const double& double_number) : DoubleNumber(double_number) {}
	void Print() const override;
private:
	const double DoubleNumber;
};

class Complex : public Value {
public:
	Complex(const double& real_part, const double& imaginary_part) : RealPart(real_part), ImaginaryPart(imaginary_part) {}
	void Print() const override;
private:
	const double RealPart;
	const double ImaginaryPart;
};
