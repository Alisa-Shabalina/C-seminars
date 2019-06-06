#pragma once

#include <iostream>
#include <iomanip>
#include <string>

using std::setw;

struct Hours {
	unsigned int Value;
	explicit Hours(unsigned int value) : Value(value) {}
};

struct Minutes {
	unsigned int Value;
	explicit Minutes(unsigned int value) : Value(value) {}
};

struct Day {
	unsigned int Value;
	explicit Day(unsigned int value) : Value(value) {}
};

struct Month {
	unsigned int Value;
	explicit Month(unsigned int value) : Value(value) {}
};

struct Year {
	unsigned int Value;
	explicit Year(unsigned int value) : Value(value) {}
};

class Time {
public:
	Time(Hours h, Minutes ms, Day d, Month m, Year y) {
		Hours = h.Value;
		if (Hours <= 12) {
			AfterMidnight = true;
		}
		else {
			AfterMidnight = false;
		}
		Minutes = ms.Value;
		Day = d.Value;
		Month = m.Value;
		Year = y.Value;
	}

	unsigned int GetHours() const { return Hours; }
	unsigned int GetMinutes() const { return Minutes; }
	unsigned int GetDay() const { return Day; }
	unsigned int GetMonth() const { return Month; }
	unsigned int GetYear() const { return Year; }

	bool IsEuropeanFormat() const { return EuropeanFormat; }
	bool IsAmericanFormat() const { return AmericanFormat; }
	bool IsAfterMidnight() const { return AfterMidnight; }

	void ForwardSwitch() {
		EuropeanFormat = false;
		AmericanFormat = true;
	}

	void ReverseSwitch() {
		EuropeanFormat = true;
		AmericanFormat = false;
	}
private:
	unsigned int Hours;
	unsigned int Minutes;
	unsigned int Day;
	unsigned int Month;
	unsigned int Year;

	bool EuropeanFormat = true;
	bool AmericanFormat = false;
	bool AfterMidnight;
};

class TimeInterval {
public:
	TimeInterval(Hours h, Minutes ms, Day d, Month m, Year y) {
		Hours = h.Value;
		Minutes = ms.Value;
		Day = d.Value;
		Month = m.Value;
		Year = y.Value;
	}

	unsigned int GetHours() const { return Hours; }
	unsigned int GetMinutes() const { return Minutes; }
	unsigned int GetDay() const { return Day; }
	unsigned int GetMonth() const { return Month; }
	unsigned int GetYear() const { return Year; }
private:
	unsigned int Hours;
	unsigned int Minutes;
	unsigned int Day;
	unsigned int Month;
	unsigned int Year;
};

struct Date {
	unsigned int Day;
	unsigned int Month;
	unsigned int Year;

	Date(unsigned int d, unsigned int m, unsigned int y) : Day(d), Month(m), Year(y) {}
};

unsigned int NumberOfDaysInMonth(const unsigned int& month);
Date CreateValidDate(const unsigned int& d, const unsigned int& m, const unsigned int& y);

inline std::ostream& operator<<(std::ostream& os, const Time& time);

inline Time operator+(const Time& T_lhs, const TimeInterval& TI_rhs);
inline Time operator-(const Time& T_lhs, const TimeInterval& TI_rhs);

inline TimeInterval operator-(const Time& lhs, const Time& rhs);

inline TimeInterval operator+(const TimeInterval& lhs, const TimeInterval& rhs);
inline TimeInterval operator-(const TimeInterval& lhs, const TimeInterval& rhs);