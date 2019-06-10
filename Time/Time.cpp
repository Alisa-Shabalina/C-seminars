#include "Time.h"

std::ostream& operator<<(std::ostream& os, const Time& time) {
	if (time.IsEuropeanFormat()) {
		os << setfill('0') << setw(2) << time.GetHours() << ':' <<
			setfill('0') << setw(2) << time.GetMinutes() << ' ' <<
			setfill('0') << setw(2) << time.GetDay() << '/' <<
			setfill('0') << setw(2) << time.GetMonth() << '/' <<
			setfill('0') << setw(4) << time.GetYear() << endl;
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
		os << setfill('0') << setw(2) << new_hours << ':' <<
			setfill('0') << setw(2) << time.GetMinutes() << ' ' <<
			setfill('0') << setw(2) << word << ' ' <<
			setfill('0') << setw(2) << time.GetMonth() << '/' <<
			setfill('0') << setw(2) << time.GetDay() << '/' <<
			setfill('0') << setw(4) << time.GetYear() << endl;
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const TimeInterval& time_interval) {
	os << setfill('0') << setw(2) << time_interval.GetMinutes() << " minutes, " <<
		setfill('0') << setw(2) << time_interval.GetHours() << " hours, " <<
		setfill('0') << setw(2) << time_interval.GetDay() << " days, " <<
		setfill('0') << setw(2) << time_interval.GetMonth() << " months, " <<
		setfill('0') << setw(4) << time_interval.GetYear() << " years" << endl;
	return os;
}

bool TimeIsCorrect(const unsigned int& ms, const unsigned int& h, const unsigned int& d, const unsigned int& m, const unsigned int& y) {
	if (ms <= 59 && h <= 23 && d <= 31 && m <= 12) {
		return true;
	}
	else {
		return false;
	}
}

Time operator+(const Time& T_lhs, const TimeInterval& TI_rhs) {
	unsigned int new_minutes = T_lhs.GetMinutes() + TI_rhs.GetMinutes();
	unsigned int new_hours = T_lhs.GetHours() + TI_rhs.GetHours();
	unsigned int new_day = T_lhs.GetDay() + TI_rhs.GetDay();
	unsigned int new_month = T_lhs.GetMonth() + TI_rhs.GetMonth();
	unsigned int new_year = T_lhs.GetYear() + TI_rhs.GetYear();

	if (TimeIsCorrect(new_minutes, new_hours, new_day, new_month, new_year)) {
		return Time(Hours(new_hours), Minutes(new_minutes), Day(new_day), Month(new_month), Year(new_year));
	}
	else {
		unsigned int T_lhs_in_ms = (T_lhs.GetDay() + (T_lhs.GetMonth() - 1) * 31 + T_lhs.GetYear() * 372) * 24 * 60 + T_lhs.GetHours() * 60 + T_lhs.GetMinutes();
		unsigned int TI_rhs_in_ms = (TI_rhs.GetDay() + (TI_rhs.GetMonth() - 1) * 31 + TI_rhs.GetYear() * 372) * 24 * 60 + TI_rhs.GetHours() * 60 + TI_rhs.GetMinutes();
		unsigned int res = T_lhs_in_ms + TI_rhs_in_ms;
		new_year = res / (372 * 24 * 60);
		new_month = (res % (372 * 24 * 60)) / (31 * 60 * 24);
		new_day = ((res % (372 * 24 * 60)) % (31 * 60 * 24)) / (24 * 60);
		new_hours = (((res % (372 * 24 * 60)) % (31 * 60 * 24)) % (24 * 60)) / 60;
		new_minutes = (((res % (372 * 24 * 60)) % (31 * 60 * 24)) % (24 * 60)) % 60;
		return Time(Hours(new_hours), Minutes(new_minutes), Day(new_day), Month(new_month), Year(new_year));
	}
}

Time operator-(const Time& T_lhs, const TimeInterval& TI_rhs) {
	if (T_lhs.GetYear() >= TI_rhs.GetYear()) {
		unsigned int new_minutes = T_lhs.GetMinutes() - TI_rhs.GetMinutes();
		unsigned int new_hours = T_lhs.GetHours() - TI_rhs.GetHours();
		unsigned int new_day = T_lhs.GetDay() - TI_rhs.GetDay();
		unsigned int new_month = T_lhs.GetMonth() - TI_rhs.GetMonth();
		unsigned int new_year = T_lhs.GetYear() - TI_rhs.GetYear();

		if (TimeIsCorrect(new_minutes, new_hours, new_day, new_month, new_year)) {
			return Time(Hours(new_hours), Minutes(new_minutes), Day(new_day), Month(new_month), Year(new_year));
		}
		else {
			unsigned int T_lhs_in_ms = (T_lhs.GetDay() + (T_lhs.GetMonth() - 1) * 31 + T_lhs.GetYear() * 372) * 24 * 60 + T_lhs.GetHours() * 60 + T_lhs.GetMinutes();
			unsigned int TI_rhs_in_ms = (TI_rhs.GetDay() + (TI_rhs.GetMonth() - 1) * 31 + TI_rhs.GetYear() * 372) * 24 * 60 + TI_rhs.GetHours() * 60 + TI_rhs.GetMinutes();
			unsigned int res = T_lhs_in_ms - TI_rhs_in_ms;
			new_year = res / (372 * 24 * 60);
			new_month = (res % (372 * 24 * 60)) / (31 * 60 * 24);
			new_day = ((res % (372 * 24 * 60)) % (31 * 60 * 24)) / (24 * 60);
			new_hours = (((res % (372 * 24 * 60)) % (31 * 60 * 24)) % (24 * 60)) / 60;
			new_minutes = (((res % (372 * 24 * 60)) % (31 * 60 * 24)) % (24 * 60)) % 60;
			return Time(Hours(new_hours), Minutes(new_minutes), Day(new_day), Month(new_month), Year(new_year));
		}
	}
	else {
		return Time(Hours(0), Minutes(0), Day(0), Month(0), Year(0));
	}
}

TimeInterval operator-(const Time& lhs, const Time& rhs) {
	if (lhs.GetYear() >= rhs.GetYear()) {
		unsigned int new_minutes = lhs.GetMinutes() - rhs.GetMinutes();
		unsigned int new_hours = lhs.GetHours() - rhs.GetHours();
		unsigned int new_day = lhs.GetDay() - rhs.GetDay();
		unsigned int new_month = lhs.GetMonth() - rhs.GetMonth();
		unsigned int new_year = lhs.GetYear() - rhs.GetYear();
		if (TimeIsCorrect(new_minutes, new_hours, new_day, new_month, new_year)) {
			return TimeInterval(Hours(new_hours), Minutes(new_minutes), Day(new_day), Month(new_month), Year(new_year));
		}
		else {
			unsigned int lhs_in_ms = (lhs.GetDay() + (lhs.GetMonth() - 1) * 31 + lhs.GetYear() * 372) * 24 * 60 + lhs.GetHours() * 60 + lhs.GetMinutes();
			unsigned int rhs_in_ms = (rhs.GetDay() + (rhs.GetMonth() - 1) * 31 + rhs.GetYear() * 372) * 24 * 60 + rhs.GetHours() * 60 + rhs.GetMinutes();
			unsigned int res = lhs_in_ms - rhs_in_ms;
			new_year = res / (372 * 24 * 60);
			new_month = (res % (372 * 24 * 60)) / (31 * 60 * 24);
			new_day = ((res % (372 * 24 * 60)) % (31 * 60 * 24)) / (24 * 60);
			new_hours = (((res % (372 * 24 * 60)) % (31 * 60 * 24)) % (24 * 60)) / 60;
			new_minutes = (((res % (372 * 24 * 60)) % (31 * 60 * 24)) % (24 * 60)) % 60;
			return TimeInterval(Hours(new_hours), Minutes(new_minutes), Day(new_day), Month(new_month), Year(new_year));
		}
	}
	else {
		return TimeInterval(Hours(0), Minutes(0), Day(0), Month(0), Year(0));
	}
}

TimeInterval operator+(const TimeInterval& lhs, const TimeInterval& rhs) {
	unsigned int new_minutes = lhs.GetMinutes() + rhs.GetMinutes();
	unsigned int new_hours = lhs.GetHours() + rhs.GetHours();
	unsigned int new_day = lhs.GetDay() + rhs.GetDay();
	unsigned int new_month = lhs.GetMonth() + rhs.GetMonth();
	unsigned int new_year = lhs.GetYear() + rhs.GetYear();
	if (TimeIsCorrect(new_minutes, new_hours, new_day, new_month, new_year)) {
		return TimeInterval(Hours(new_hours), Minutes(new_minutes), Day(new_day), Month(new_month), Year(new_year));
	}
	else {
		unsigned int lhs_in_ms = (lhs.GetDay() + (lhs.GetMonth() - 1) * 31 + lhs.GetYear() * 372) * 24 * 60 + lhs.GetHours() * 60 + lhs.GetMinutes();
		unsigned int rhs_in_ms = (rhs.GetDay() + (rhs.GetMonth() - 1) * 31 + rhs.GetYear() * 372) * 24 * 60 + rhs.GetHours() * 60 + rhs.GetMinutes();
		unsigned int res = lhs_in_ms + rhs_in_ms;
		new_year = res / (372 * 24 * 60);
		new_month = (res % (372 * 24 * 60)) / (31 * 60 * 24);
		new_day = ((res % (372 * 24 * 60)) % (31 * 60 * 24)) / (24 * 60);
		new_hours = (((res % (372 * 24 * 60)) % (31 * 60 * 24)) % (24 * 60)) / 60;
		new_minutes = (((res % (372 * 24 * 60)) % (31 * 60 * 24)) % (24 * 60)) % 60;
		return TimeInterval(Hours(new_hours), Minutes(new_minutes), Day(new_day), Month(new_month), Year(new_year));
	}
}

TimeInterval operator-(const TimeInterval& lhs, const TimeInterval& rhs) {
	if (lhs.GetYear() >= rhs.GetYear()) {
		unsigned int new_minutes = lhs.GetMinutes() - rhs.GetMinutes();
		unsigned int new_hours = lhs.GetHours() - rhs.GetHours();
		unsigned int new_day = lhs.GetDay() - rhs.GetDay();
		unsigned int new_month = lhs.GetMonth() - rhs.GetMonth();
		unsigned int new_year = lhs.GetYear() - rhs.GetYear();
		if (TimeIsCorrect(new_minutes, new_hours, new_day, new_month, new_year)) {
			return TimeInterval(Hours(new_hours), Minutes(new_minutes), Day(new_day), Month(new_month), Year(new_year));
		}
		else {
			unsigned int lhs_in_ms = (lhs.GetDay() + (lhs.GetMonth() - 1) * 31 + lhs.GetYear() * 372) * 24 * 60 + lhs.GetHours() * 60 + lhs.GetMinutes();
			unsigned int rhs_in_ms = (rhs.GetDay() + (rhs.GetMonth() - 1) * 31 + rhs.GetYear() * 372) * 24 * 60 + rhs.GetHours() * 60 + rhs.GetMinutes();
			unsigned int res = lhs_in_ms - rhs_in_ms;
			new_year = res / (372 * 24 * 60);
			new_month = (res % (372 * 24 * 60)) / (31 * 60 * 24);
			new_day = ((res % (372 * 24 * 60)) % (31 * 60 * 24)) / (24 * 60);
			new_hours = (((res % (372 * 24 * 60)) % (31 * 60 * 24)) % (24 * 60)) / 60;
			new_minutes = (((res % (372 * 24 * 60)) % (31 * 60 * 24)) % (24 * 60)) % 60;
			return TimeInterval(Hours(new_hours), Minutes(new_minutes), Day(new_day), Month(new_month), Year(new_year));
		}
	}
	else {
		return TimeInterval(Hours(0), Minutes(0), Day(0), Month(0), Year(0));
	}
}