#ifndef REPORT_DRIVER
// Implementation for Cashier

#include "Cashier.h"
#include "Book.h"

using namespace std;

void Cashier::decrementBookQuant(int num, Book &b)
{
	// Lower quantity of bought book by 1
	// Can go to 0 but not negative
	if (b.getQuant() <= 0)
	{
		string exception =  "This book does not exist in our database and cannot be purchased.";
		throw exception;
	}

	b.quantity -= num;
}
#endif //REPORT_DRIVER