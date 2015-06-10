//
// Created by Brandon Yost on 5/9/15.
//
#include "Price.h"

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
	// Possibly prompt the user to enter price
	// cout << "Please enter a price: ";
	input >> price;
	P.total_cents = int(price * 100);
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

bool operator<(const Price &p1, const Price &p2)
{
	return p1.total_cents > p2.total_cents; 
}

bool operator>(const Price &p1, const Price &p2)
{
	return p1.total_cents > p2.total_cents; 
}

Price operator * (const Price& left, const double &right)
{
	// Return a multiplication between a Price object and a double as Price
	Price temp;
	temp.total_cents = int(left.total_cents * right);
	return temp;
}

Price operator * (const double& left, const Price &right)
{
	Price temp;
	temp.total_cents = int(left * right.total_cents);
	return temp;
}
/*
Price operator+ (const Price &left, const Price &right)
{
	Price temp;
	temp.total_cents = left.total_cents + right.total_cents;
	return temp;
}
*/
Price& Price::operator+=(const Price &p) {
	total_cents += p.total_cents;
	return (*this);
}


