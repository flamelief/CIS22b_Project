// Specification File for Cashier Class

#ifndef CASHIER_H
#define CASHIER_H

#include "Book.h"

const double TAX = 0.925;

class Cashier
{
private:
	Price sales;
	Book book;
public:
	Cashier();
	double getTax() const { return TAX; }
	void setSubtotal(Price s) { sales = s; }
	Price getSubtotal() const { return sales; }
	Price getTotal() const { return sales + sales * TAX; } 
	// Decrement book from Inventory database when purchased
	void decrementBook(Book);
};
#endif