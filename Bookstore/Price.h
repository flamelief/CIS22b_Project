//
// Created by Brandon Yost on 5/9/15.
//

#ifndef BOOKSTORE_PRICE_H
#define BOOKSTORE_PRICE_H

#include <iostream>

using namespace std;

class Price {
private:
	int total_cents;
public:
	Price();
	Price(int dollars, int cents);
	friend ostream& operator<<(ostream &output, const Price &P);
	friend istream& operator>>(istream &input, Price &P);
	inline int getDollars() const;
	inline int getCents() const;
	void setPrice(int dollars, int cents);
	inline bool isValid();
	Price operator*(const double &);
	Price operator*(const Price &);
	Price operator+(const Price &);
	Price& operator+=(const Price&);
	friend bool operator<(const Price &, const Price &);
	friend bool operator>(const Price &, const Price &);
};


#endif //BOOKSTORE_PRICE_H
