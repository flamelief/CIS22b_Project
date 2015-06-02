// Specification File for Cashier Class

#ifndef CASHIER_H
#define CASHIER_H

#include "Book.h"

const double TAX = 0.10;

class Cashier
{
private:
	Price sales;
	Book book;
public:
	double getTax() const { return TAX; }
	Price getSubtotal() const { return sales; }
	//Price getTotal() const { return sales + (sales * TAX; }
	// Subtract book from Inventory database
};
#endif