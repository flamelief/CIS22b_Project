#include "Date.h"


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
bool Date::isValid() {
	if (year >= 0 && month >= Jan && month <= Dec){
		if (day >= 1) {
			if (month == Jan || month == Mar || month == May
				|| month == Jul || month == Aug || month == Oct || month == Dec) {
				return day <= 31;
			}
			else if (month == Feb) {
				if (year % 4) return day <= 28;
				else return day <= 29;
			}
			return day <= 30;
		}
	}
	return false;
}

ostream& operator<<(ostream &output, const Date &D){
	output << D.month << "/" << D.day << "/" << D.year;
	return output;
}

istream& operator>>(istream &input, Date &D){
	char delim1, delim2;
	input >> D.month >> delim1 >> D.day >> delim2 >> D.year;
	if (!(input && delim1 == '/' && delim2 == '/' && D.isValid())){
		input.setstate(ios::failbit);
	}
	return input;
}





Date::~Date()
{
}
