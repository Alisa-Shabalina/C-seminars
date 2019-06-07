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

	void ForwardSwitch() {
		EuropeanFormat = false;
		AmericanFormat = true;
	}

	void ReverseSwitch() {
		EuropeanFormat = true;
		AmericanFormat = false;
	}

	unsigned int GetDateInDays() const;

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

	unsigned int GetDateInDays() const;

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

std::ostream& operator<<(std::ostream& os, const Time& time);
std::ostream& operator<<(std::ostream& os, const TimeInterval& time_interval);

unsigned int NumberOfDaysInMonth(const unsigned int& month) {
	if (month == 2) {
		return 28;
	}
	else {
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			return 30;
		}
		else {
			return 31;
		}
	}
}

bool DateIsCorrect(const Date& date) {
	if (date.Day <= NumberOfDaysInMonth(date.Month) && date.Month <= 12) {
		return true;
	}
	else {
		return false;
	}
}

Date CreateValidDate(const unsigned int& d, const unsigned int& m, const unsigned int& y) {
	Date new_date(d, m, y);

	if (DateIsCorrect(new_date)) {
		return new_date;
	}
	else {
		if (new_date.Month > 12) {
			new_date.Month -= 12;
			new_date.Year += 1;
		}
		else {
			auto num_of_days = NumberOfDaysInMonth(new_date.Month);
			if (new_date.Day > num_of_days) {
				new_date.Day -= num_of_days;
				new_date.Month += 1;
				//if (DateIsCorrect(new_date)) {
					//return new_date;
				//}
				//else {
					return CreateValidDate(new_date.Day, new_date.Month, new_date.Year);
				//}
			}
		}
	}

//	if (new_date.Month > 12) {
//		new_date.Month -= 12;
//		new_date.Year += 1;
//	}
//	else {
//		unsigned int nums_of_days = NumberOfDaysInMonth(new_date.Month);
//		if (new_date.Day > nums_of_days) {
//			new_date.Day -= nums_of_days;
//			new_date.Month += 1;
//		}
//		else {
//			new_date = CreateValidDate(new_date.Day, new_date.Month, new_date.Year);
//		}
//	}
//	return new_date;
}

inline Time operator+(const Time& T_lhs, const TimeInterval& TI_rhs) {
	unsigned int new_minutes = T_lhs.GetMinutes() + TI_rhs.GetMinutes();
	unsigned int new_hours = T_lhs.GetHours() + TI_rhs.GetHours();
	unsigned int new_day = T_lhs.GetDay() + TI_rhs.GetDay();
	unsigned int new_month = T_lhs.GetMonth() + TI_rhs.GetMonth();
	unsigned int new_year = T_lhs.GetYear() + TI_rhs.GetYear();
	if (new_minutes > 59) {
		new_minutes -= 60;
		new_hours += 1;
	}
	else {
		if (new_hours > 23) {
			new_hours -= 24;
			new_day += 1;
		}
		else {
			Date valid_date = CreateValidDate(new_day, new_month, new_year);
			new_day = valid_date.Day;
			new_month = valid_date.Month;
			new_year = valid_date.Year;
		}
	}

	return Time(Hours(new_hours), Minutes(new_minutes), Day(new_day), Month(new_month), Year(new_year));
}

inline Time operator-(const Time& T_lhs, const TimeInterval& TI_rhs) {
	if (T_lhs.GetYear() >= TI_rhs.GetYear()) {
		unsigned int new_minutes = T_lhs.GetMinutes() - TI_rhs.GetMinutes();
		unsigned int new_hours = T_lhs.GetHours() - TI_rhs.GetHours();
		unsigned int new_day = T_lhs.GetDay() - TI_rhs.GetDay();
		unsigned int new_month = T_lhs.GetMonth() - TI_rhs.GetMonth();
		unsigned int new_year = T_lhs.GetYear() - TI_rhs.GetYear();
		if (new_minutes > 59) {
			new_minutes -= 60;
			new_hours += 1;
		}
		else {
			if (new_hours > 23) {
				new_hours -= 24;
				new_day += 1;
			}
			else {
				Date valid_date = CreateValidDate(new_day, new_month, new_year);
				new_day = valid_date.Day;
				new_month = valid_date.Month;
				new_year = valid_date.Year;
			}
		}

		return Time(Hours(new_hours), Minutes(new_minutes), Day(new_day), Month(new_month), Year(new_year));
	}
	else {
		return Time(Hours(0), Minutes(0), Day(0), Month(0), Year(0));
	}
}

inline TimeInterval operator-(const Time& lhs, const Time& rhs) {
	if (lhs.GetHours() >= rhs.GetHours() && lhs.GetMinutes() >= rhs.GetMinutes() &&
		lhs.GetDay() >= rhs.GetDay() && lhs.GetMonth() >= rhs.GetMonth() &&
		lhs.GetYear() >= rhs.GetYear()) {
		unsigned int new_minutes = lhs.GetMinutes() - rhs.GetMinutes();
		unsigned int new_hours = lhs.GetHours() - rhs.GetHours();
		unsigned int new_day = lhs.GetDay() - rhs.GetDay();
		unsigned int new_month = lhs.GetMonth() - rhs.GetMonth();
		unsigned int new_year = lhs.GetYear() - rhs.GetYear();
		if (new_minutes > 59) {
			new_minutes -= 60;
			new_hours += 1;
		}
		else {
			if (new_hours > 23) {
				new_hours -= 24;
				new_day += 1;
			}
			else {
				Date valid_date = CreateValidDate(new_day, new_month, new_year);
				new_day = valid_date.Day;
				new_month = valid_date.Month;
				new_year = valid_date.Year;
			}
		}

		return TimeInterval(Hours(new_hours), Minutes(new_minutes), Day(new_day), Month(new_month), Year(new_year));
	}
	else {
		return TimeInterval(Hours(0), Minutes(0), Day(0), Month(0), Year(0));
	}
}

inline TimeInterval operator+(const TimeInterval& lhs, const TimeInterval& rhs) {
	unsigned int new_minutes = lhs.GetMinutes() + rhs.GetMinutes();
	unsigned int new_hours = lhs.GetHours() + rhs.GetHours();
	unsigned int new_day = lhs.GetDay() + rhs.GetDay();
	unsigned int new_month = lhs.GetMonth() + rhs.GetMonth();
	unsigned int new_year = lhs.GetYear() + rhs.GetYear();
	if (new_minutes > 59) {
		new_minutes -= 60;
		new_hours += 1;
	}
	else {
		if (new_hours > 23) {
			new_hours -= 24;
			new_day += 1;
		}
		else {
			Date valid_date = CreateValidDate(new_day, new_month, new_year);
			new_day = valid_date.Day;
			new_month = valid_date.Month;
			new_year = valid_date.Year;
		}
	}

	return TimeInterval(Hours(new_hours), Minutes(new_minutes), Day(new_day), Month(new_month), Year(new_year));
}

inline TimeInterval operator-(const TimeInterval& lhs, const TimeInterval& rhs) {
	if (lhs.GetHours() >= rhs.GetHours() && lhs.GetMinutes() >= rhs.GetMinutes() &&
		lhs.GetDay() >= rhs.GetDay() && lhs.GetMonth() >= rhs.GetMonth() &&
		lhs.GetYear() >= rhs.GetYear()) {
		unsigned int new_minutes = lhs.GetMinutes() - rhs.GetMinutes();
		unsigned int new_hours = lhs.GetHours() - rhs.GetHours();
		unsigned int new_day = lhs.GetDay() - rhs.GetDay();
		unsigned int new_month = lhs.GetMonth() - rhs.GetMonth();
		unsigned int new_year = lhs.GetYear() - rhs.GetYear();
		if (new_minutes > 59) {
			new_minutes -= 60;
			new_hours += 1;
		}
		else {
			if (new_hours > 23) {
				new_hours -= 24;
				new_day += 1;
			}
			else {
				Date valid_date = CreateValidDate(new_day, new_month, new_year);
				new_day = valid_date.Day;
				new_month = valid_date.Month;
				new_year = valid_date.Year;
			}
		}

		return TimeInterval(Hours(new_hours), Minutes(new_minutes), Day(new_day), Month(new_month), Year(new_year));
	}
	else {
		return TimeInterval(Hours(0), Minutes(0), Day(0), Month(0), Year(0));
	}
}