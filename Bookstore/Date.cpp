#include "Date.h"
#include <algorithm>


Date::Date(int d, int m, int y)
{
	day = d, month = m, year = y;
}
int Date::getDay() const { return day; }
void Date::setDay(int d) { day = d; }
int Date::getMonth() const { return month; }
void Date::setMonth(int m) { month = m; }
int Date::getYear() const { return year; }
void Date::setYear(int y) { year = y; }

ostream& operator<<(ostream &output, const Date &D){
	output << setfill('0') << setw(2) << D.month << "/" << setfill('0') << setw(2) << D.day << "/" << setfill('0') << setw(4) << D.year;
	return output;
}

istream& operator>>(istream &input, Date &D){
	char delim1, delim2;
	input >> D.month >> delim1 >> D.day >> delim2 >> D.year;
	if (!(input && delim1 == '/' && delim2 == '/')){
		input.setstate(ios::failbit);
	}
	return input;
}

// Date compare
bool Date::operator>(const Date& date)
{
	if (year < date.year) return true;
	else if (year == date.year)
	{
		if (month < date.month) return true;
		else if (month == date.month)
		{
			if (day < date.day) return true;
		}
	}
	return false;
}


Date::~Date()
{
}
