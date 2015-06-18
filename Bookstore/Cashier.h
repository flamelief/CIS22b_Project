// Specification File for Cashier Class
#ifndef CASHIER_H
#define CASHIER_H

#include "Interface.h"
#include "Price.h"

/* Cashier class decrements the amount of particular book(s) in the interface vector, calculates the price of book(s) with tax, and
displays the cashier menu
It is a child class for Interface, as it interacts with the vector of books
*/

class Cashier : private Interface
{
private: 
	//Price sales;
public:
	Cashier();
	Cashier(string);
	// Make a function that adds up the totals of multiple books or a book array
	//double getTax() const { return TAX; }
	//void setSubtotal(Price s) { sales = s; }
	//Price getSubtotal() const { return sales; }
	Price getTotal(int, Book *); // Adds up the prices
	Price getTotal(int, vector <Book>);
	Book decrementBookQuant(/*vector <Book> &*/string); // Decrements the quantity of a book when it is purchased
	void printCashierMenu(/*vector <Book> &*/); // Prompts user for books they wish to purchase and then prints them out with the total cost
										 
};
#endif
