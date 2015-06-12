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
	output << setfill('0') << setw(2) << D.month << "/" << setfill('0') << setw(2) << D.day << "/" << setfill('0') << setw(4) << D.year;
	return output;
}

istream& operator>>(istream &input, Date &D){
	char delim1, delim2;
	input >> D.month >> delim1 >> D.day >> delim2 >> D.year;
	if (!(input && delim1 == '/' && delim2 == '/' )){
		input.setstate(ios::failbit);
	}
	return input;
}

bool datefunction(Book date1, Book date2)
{
	return date1.getDate() < date2.getDate();

}

bool operator<(Book date1, Book date2)
{
	if (date1.year < date2.year)
		return true;
	else if (date1.year == date2.year)
	{
		if date1.month < date2.month
			return true;
		else if (date1.month == date2.month)
		{
			if (date1.day < date2.day)
				return true;
			else
			{
				return false;
			}
		}
	}


} 




Date::~Date()
{
}
