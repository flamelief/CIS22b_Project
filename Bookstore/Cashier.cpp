#ifndef REPORT_DRIVER
// Implementation for Cashier

#include "Cashier.h"
#include "Book.h"

using namespace std;

Cashier::Cashier() {}

void Cashier::decrementBookQuant(int num, vector <Book> &b)
{
	// Find which books to decrement
	// Lower quantity of bought book by 1
	// Can go to 0 but not negative



	/*
	if ( b.at( find(b.quantity) ) <= 0 )
	{
		throw "This book does not exist in our database and cannot be purchased.";
	}

	b.quantity -= num; // decrement by 1
	*/
}
#endif //REPORT_DRIVER