#ifndef REPORT_DRIVER
// Implementation for Cashier

#include <iostream>
#include <iomanip>
#include <ctime>

#include "Cashier.h"
#include "Book.h"

using namespace std;

Cashier::Cashier() : Interface(/*fileName*/) {}

Price Cashier::getTotal(int size, Book * b)
{
	// either make a temp book pointer to avoid changing data or make const
	Price total;
	Book * temp = b;
	int index;
	
	for (index = 0; index < size; index++)
	{
		total += temp->getTotal();
		temp++;
	}
	//for (index = 0; index < size; index++)
	//{
	//	b--;
	//}
	return total;
}

Book Cashier::decrementBookQuant(/*vector <Book> &b*/string id)
{
	int index;
	/*string userInput;
	// Find which book to decrement by ISBN or Title
	cout << "Book to purchase by ISBN or title:";
	cin >> userInput;*/
	
	// find the book with the right title by iterating through the vector (linear search)
	for (index = 0; index < books.size(); index++)
	{
		if ( (books.at(index).getTitle() == id) || ( books.at(index).getISBN() == id) )
		{
			if (books.at(index).getQuant() <= 0)
			{
				throw "This book does not exist in our database and cannot be purchased.";
			}
			books.at(index).quantity -= 1;
			return books.at(index);
		}
	}
	// Need to include error testing in case the book is not found

	/*
	
	if ( b.at( find(b.quantity) ) <= 0 )
	{
		throw "This book does not exist in our database and cannot be purchased.";
	}

	b.quantity -= 1; // decrement by 1
	*/
}

void Cashier::printCashierMenu(/*vector <Book> &b*/)
{
	int index = 0;
	int amount = 0;
	char * temp = "";
	// establish which book(s) are being purchased, the book objects in the vector
	// a loop type to get books
	// dynamically allocate a local pointer to hold the books and then add values to that pointer

	cout << "How many books are you purchasing?" << endl;
	cin >> amount;
	Book * boughtBooks = new Book[amount];

	// see if there is space
	if (boughtBooks == nullptr)
	{
		cout << "Not enough space for this pointer, exiting function." << endl;
		return;
	}

	//cout << "What book are you purchasing? Type either the ISBN or Title or 'n' to quit." << endl;
	for (index = 0; index < amount; index++)
	{
		cin >> temp;
		//while (!islower(*temp))
		//{
		//if (isupper(*temp)) // Title branch
		//{
			// call the bookDecrementQuant function and store that return value in the current index of pointer
			*(boughtBooks + index) = decrementBookQuant(temp);
			//boughtBooks->setTitle(temp);
			//boughtBooks++;
		//}
		//else // ISBN branch
		//{
			//boughtBooks->setISBN(temp);
			//boughtBooks++;
		//}
		//cout << "Would you like to purchase another book? Type either the ISBN or Title or 'n' to quit." << endl;
	}
	//} 
	cout << setw(100) << "Team 1 Book Sellers" << endl << endl;
	cout << setw(100) << "Date: " << time(0)/*change to make current time*/ << endl << endl;
	cout << setw(25) << "Qty " << " ISBN " << setfill('\s') << setw(50) << "Title" 
		<< setfill('\s') << "Price" << setw(25) << "Total" << endl;
	// Write out each book's information
	for (index = 0; index < amount; index++)
	{
		cout << setw(25) << boughtBooks->getQuant() << "  " << boughtBooks->getISBN() << setfill('\s') << setw(50) << boughtBooks->getTitle()
			<< setfill('\s') << boughtBooks->getRetail() << setw(25) << boughtBooks->getTotal() << endl;
		// increment pointer
		boughtBooks++;
	}
	// decrement pointer
	for (index = 0; index < amount; index++)
	{
		boughtBooks--;
	}
	cout << setw(100) << setfill('-') << endl << endl;
	cout << "\t\t\t" << "Subtotal" << getTotal(amount, boughtBooks) << endl;
	cout << "\t\t\t" << "Tax" << TAX << endl;
	cout << "\t\t\t" << "Total" << getTotal(amount, boughtBooks) * TAX << endl << endl;
	cout << "Thank you for shopping at Team 1's Bookstore!" << endl;

	// delete pointer
	delete[] boughtBooks;
}
#endif //REPORT_DRIVER