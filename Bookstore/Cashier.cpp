#ifndef REPORT_DRIVER
// Implementation for Cashier

#include <iostream>

#include "Cashier.h"
#include "Book.h"

using namespace std;

Cashier::Cashier() {}

void Cashier::decrementBookQuant(vector <Book> &b)
{
	string userInput;
	int index;
	// Find which book to decrement by ISBN or Title
	cout << "Book to purchase by ISBN or title:";
	cin >> userInput;
	
	// find the book with the right title by iterating through the vector (linear search)
	for (index = 0; index < b.size(); index++)
	{
		if ( (b.at(index).getTitle() == userInput) || ( b.at(index).getISBN() == userInput) )
		{
			b.at(index).quantity -= 1;
			break;
		}
	}
	 
	/*
	
	if ( b.at( find(b.quantity) ) <= 0 )
	{
		throw "This book does not exist in our database and cannot be purchased.";
	}

	b.quantity -= 1; // decrement by 1
	*/
}
#endif //REPORT_DRIVER