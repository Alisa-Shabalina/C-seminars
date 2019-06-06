#include "Time.h"

inline std::ostream& operator<<(std::ostream& os, const Time& time) {
	if (time.IsEuropeanFormat()) {
		os << setw(2) << time.GetHours() << ':' << setw(2) << time.GetMinutes() << ' ' <<
			setw(2) << time.GetDay() << '/' <<
			setw(2) << time.GetMonth() << '/' <<
			setw(2) << time.GetYear() << std::endl;
	}
	else {
		std::string word;
		unsigned int new_hours;
		if (time.IsAfterMidnight()) {
			word = "AM";
			new_hours = time.GetHours();
		}
		else {
			word = "PM";
			new_hours = time.GetHours() - 12;
		}
		os << setw(2) << new_hours << ':' << setw(2) << time.GetMinutes() << ' ' <<
			setw(2) << word << ' ' <<
			setw(2) << time.GetMonth() << '/' <<
			setw(2) << time.GetDay() << '/' <<
			setw(2) << time.GetYear() << std::endl;
	}
}

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

Date CreateValidDate(const unsigned int& d, const unsigned int& m, const unsigned int& y) {
	Date new_date(d, m, y);
	if (new_date.Month > 12) {
		new_date.Month -= 12;
		new_date.Year += 1;
	}
	else {
		unsigned int nums_of_days = NumberOfDaysInMonth(new_date.Month);
		if (new_date.Day > nums_of_days) {
			new_date.Day -= nums_of_days;
			new_date.Month += 1;
		}
		else {
			new_date = CreateValidDate(new_date.Day, new_date.Month, new_date.Year);
		}
	}
	return new_date;
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
		}
	}

	return Time(Hours(new_hours), Minutes(new_minutes), Day(new_day), Month(new_month), Year(new_year));
}

inline Time operator-(const Time& T_lhs, const TimeInterval& TI_rhs) {
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
		}
	}

	return Time(Hours(new_hours), Minutes(new_minutes), Day(new_day), Month(new_month), Year(new_year));
}