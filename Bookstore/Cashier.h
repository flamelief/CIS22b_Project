// Specification File for Cashier Class
#ifndef REPORT_DRIVER
#ifndef CASHIER_H
#define CASHIER_H

#include "Interface.h"
#include "Price.h"

/* Cashier class stores the prices of the books and calculates the price with tax
It is a child class for Interface, as it interacts with the vector of books
*/

const double TAX = 0.925; // 9.25% sales tax

class Cashier : public Interface
{
private: 
	Price sales;
public:
	Cashier();
	double getTax() const { return TAX; }
	void setSubtotal(Price s) { sales = s; }
	Price getSubtotal() const { return sales; }
	Price getTotal() { return sales + sales * TAX; } 
	void decrementBookQuant(vector <Book>&); // gets access as child class of interface, inherits protected vector<Book> books
										 // Decrements the quantity of a book when it is purchased
};
#endif
#endif //REPORT_DRIVER