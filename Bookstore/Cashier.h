// Specification File for Cashier Class
#ifndef CASHIER_H
#define CASHIER_H

#include "Interface.h"

class Book;

/* Cashier class decrements the amount of particular book(s) in the interface vector, calculates the price of book(s) with tax, and
displays the cashier menu
It is a child class for Interface, as it interacts with the vector of books
*/

class Cashier : private Interface
{
private: 
	//Disallow copy constructor
	Cashier(const Cashier&);
	Cashier& operator=(Cashier&);

	double getTotalCost(vector <Book>); // Adds up the prices of multiple books
	int getBook(string);
	void decrementBookQuant(int); // Decrements the quantity of a book when it is purchased
	void printCashierMenu(); // Prompts user for books they wish to purchase and then prints them out with the total cost
public:
	Cashier();
	Cashier(string);
};
#endif
