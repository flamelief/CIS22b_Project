//
// Created by Brandon Yost on 5/9/15.
//
#ifndef BOOKSTORE_PRICE_H
#include "Price.h"
#endif

Price::Price(){
	total_cents = 0;
}
Price::Price(int dollars, int cents){
	total_cents = dollars * 100;
	total_cents += cents;
}

ostream& operator<<(ostream &output, const Price &P){
	output << "$" << P.getDollars() << "." << P.getCents();
	if (!(P.getCents() % 10)) output << "0";
	return output;
}

istream& operator>>(istream &input, Price &P){
	double price;
	input >> price;
	P.total_cents = static_cast<int>(floor(price * 100));
	if (!(input && P.isValid())) {
		input.setstate(ios::failbit);
	}
	return input;
}

void Price::setPrice(int dollars, int cents) {
	total_cents = dollars * 100;
	total_cents += cents;
}

int Price::getDollars() const {
	return total_cents / 100;
}

int Price::getCents() const {
	return total_cents % 100;
};

bool Price::isValid(){
	return total_cents >= 0;
}

/*Price Price::operator * (const double &right)
{
	// Return a multiplication between a Price object and a double as Price
	total_cents = total_cents * right;
	return *this;
}
*/

