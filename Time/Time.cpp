#include "Time.h"

unsigned int Time::GetDateInDays() const {
	unsigned int result = Year * 365;
	if (Month == 1) {
		result += Day;
	}
	if (Month == 2) {
		result += (31 + Day);
	}
	if (Month == 3) {
		result += (31 + 28 + Day);
	}
	if (Month == 4) {
		result += (31 + 28 + 31 + Day);
	}
	if (Month == 5) {
		result += (31 + 28 + 31 + 30 + Day);
	}
	if (Month == 6) {
		result += (31 + 28 + 31 + 30 + 31 + Day);
	}
	if (Month == 7) {
		result += (31 + 28 + 31 + 30 + 31 + 30 + Day);
	}
	if (Month == 8) {
		result += (31 + 28 + 31 + 30 + 31 + 30 + 31 + Day);
	}
	if (Month == 9) {
		result += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + Day);
	}
	if (Month == 10) {
		result += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + Day);
	}
	if (Month == 11) {
		result += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + Day);
	}
	if (Month == 12) {
		result += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + Day);
	}

	return result;
}

unsigned int TimeInterval::GetDateInDays() const {
	unsigned int result = Year * 365;
	if (Month == 1) {
		result += Day;
	}
	if (Month == 2) {
		result += (31 + Day);
	}
	if (Month == 3) {
		result += (31 + 28 + Day);
	}
	if (Month == 4) {
		result += (31 + 28 + 31 + Day);
	}
	if (Month == 5) {
		result += (31 + 28 + 31 + 30 + Day);
	}
	if (Month == 6) {
		result += (31 + 28 + 31 + 30 + 31 + Day);
	}
	if (Month == 7) {
		result += (31 + 28 + 31 + 30 + 31 + 30 + Day);
	}
	if (Month == 8) {
		result += (31 + 28 + 31 + 30 + 31 + 30 + 31 + Day);
	}
	if (Month == 9) {
		result += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + Day);
	}
	if (Month == 10) {
		result += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + Day);
	}
	if (Month == 11) {
		result += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + Day);
	}
	if (Month == 12) {
		result += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + Day);
	}

	return result;
}

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