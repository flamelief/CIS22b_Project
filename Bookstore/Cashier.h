// Specification File for Cashier Class
#ifndef REPORT_DRIVER
#ifndef CASHIER_H
#define CASHIER_H

#include "Book.h"

const double TAX = 0.925;

class Cashier 
{
private:
	Price sales;
public:
	Cashier();
	double getTax() const { return TAX; }
	void setSubtotal(Price s) { sales = s; }
	Price getSubtotal() const { return sales; }
	Price getTotal() const { return sales + sales * TAX; } 
	void decrementBookQuant(Book&);
};
#endif
#endif //REPORT_DRIVER