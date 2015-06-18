#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>

using namespace std;

class Date
{
private:
	enum Months {
		Jan = 1, Feb, Mar, Apr, May,
		Jun, Jul, Aug, Sep, Oct, Nov, Dec
	};
	int day, month, year;
public:
	Date(int day = 1, int month = 1, int year = 1990);
	inline int getDay() const;
	void setDay(int d);
	inline int getMonth() const;
	void setMonth(int m);
	inline int getYear() const;
	void setYear(int y);

	bool operator>(const Date&);
	friend ostream& operator<<(ostream &output, const Date &D);
	friend istream& operator>>(istream &input, Date &D);



	~Date();
};

#endif //DATE_H
