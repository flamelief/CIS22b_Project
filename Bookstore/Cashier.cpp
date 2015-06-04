// Implementation for Cashier

#include "Cashier.h"

using namespace std;

void Cashier::decrementBookQuant(Book &b)
{
	// Lower quantity of bought book by 1
	// Can go to 0 but not negative
	if (b.getQuant() <= 0)
	{
		cout << "This book does not exist in our database and cannot be purchased." << endl;
		return;
	}

	--b.quantity; // make accessible 
}