#pragma once

#include <iostream>
#include <iomanip>
#include <string>

using std::setw;
using std::setfill;
using std::endl;

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

	void Switch() {
		if (EuropeanFormat) {
			EuropeanFormat = false;
			AmericanFormat = true;
		}
		else {
			EuropeanFormat = true;
			AmericanFormat = false;
		}
	}

	//unsigned int GetDateInDays() const;

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

	//unsigned int GetDateInDays() const;

private:
	unsigned int Hours;
	unsigned int Minutes;
	unsigned int Day;
	unsigned int Month;
	unsigned int Year;

};

std::ostream& operator<<(std::ostream& os, const Time& time);
std::ostream& operator<<(std::ostream& os, const TimeInterval& time_interval);

bool TimeIsCorrect(const unsigned int& ms, const unsigned int& h, const unsigned int& d, const unsigned int& m, const unsigned int& y);

Time operator+(const Time& T_lhs, const TimeInterval& TI_rhs);
Time operator-(const Time& T_lhs, const TimeInterval& TI_rhs);

TimeInterval operator-(const Time& lhs, const Time& rhs);

TimeInterval operator+(const TimeInterval& lhs, const TimeInterval& rhs);
TimeInterval operator-(const TimeInterval& lhs, const TimeInterval& rhs);