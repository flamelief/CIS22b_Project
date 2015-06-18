#ifndef REPORT_DRIVER
// Implementation for Cashier

#include <iostream>
#include <iomanip>
#include <ctime>

#include "Cashier.h"
#include "Book.h"

using namespace std;

Cashier::Cashier() : Interface() {}

//Cashier::Cashier(string fileName) : Interface(fileName) {}

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

Price Cashier::getTotal(int size, vector <Book> b)
{
	Price total;
	int index;

	for (index = 0; index < size; index++)
	{
		total += b.at(index).getTotal();
	}
	return total;
}

Book Cashier::decrementBookQuant(/*vector <Book> &b*/string id)
{
	int index;
	Book dummy;
	string tryAgain;
	/*string userInput;
	// Find which book to decrement by ISBN or Title
	cout << "Book to purchase by ISBN or title:";
	cin >> userInput;*/
	
	// find the book with the right title by iterating through the vector (linear search)
	for (index = 0; index < books.size(); index++)
	{
		if ((books.at(index).getTitle() == id) || (books.at(index).getISBN() == id))
		{
			if (books.at(index).getQuant() <= 0)
			{
				cout << "This book does not exist in our database and cannot be purchased." << endl;
				return dummy;
			}
			books.at(index).quantity -= 1;
			return books.at(index);
		}
	}
	// Should include error testing in case the book is not found
	//do {
	cout << "For some reason, we could not find your book with the given information. Sorry for the inconvenience." << endl;
	//cin >> tryAgain;
	//if (tryAgain == "q")
	//{
		return dummy;
	//}
	//return decrementBookQuant(tryAgain);
	/*cin >> tryAgain;
	if (*tryAgain = 'q')//isupper(*tryAgain) || isdigit(*tryAgain)
	{
		throw "Goodbye";
	}
	else if (isupper(*tryAgain) || isdigit(*tryAgain) && strlen(tryAgain) == 13)
	{
		return decrementBookQuant(tryAgain);
	}

	} while ( !(*tryAgain == 'q') )
	*/

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
	string purchase;
	vector <Book> b;

	// establish which book(s) are being purchased, the book objects in the vector
	// a loop type to get books

	// dynamically allocate a local pointer to hold the books and then add values to that pointer
	
	cout << "How many books are you purchasing?" << endl;
	cin >> amount;
	/*=
	cin.get();
	Book * boughtBooks = new Book[amount];
	
	//see if there is space
	if (boughtBooks == nullptr)
	{
		cout << "Cannot dynamically allocate this pointer, exiting function." << endl;
		return;
	}
	*/
	for (index = 0; index < amount; index++)
	{
		cout << "What book are you purchasing? Type either the ISBN or Title." << endl;
		getline(cin, purchase);
		// add books from main vector into new vector for cashier purchases
		b.push_back(decrementBookQuant(purchase));
		//while (!islower(*temp))
		//{
		//if (isupper(*temp)) // Title branch
		//{
			// call the bookDecrementQuant function and store that return value in the current index of pointer
			//*(boughtBooks + index) = decrementBookQuant(purchase);
			//boughtBooks->setTitle(temp);
			//boughtBooks++;
		//}
		//else // ISBN branch
		//{
			//boughtBooks->setISBN(temp);
			//boughtBooks++;
		//}
		//cout << "Would you like to purchase another book? Type either the ISBN or Title or 'q' to quit." << endl;
	}
	//} 
	cout << "Team 1 Book Sellers" << endl << endl;
	cout << "Date: " << time(0)/*change to make current time*/ << endl << endl;
	cout << "Qty   " << "ISBN\t\t" << "Title\t\t\t" << "Price\t" << "Total" << endl;
	// Write out each book's information
	for (index = 0; index < amount; index++)
	{
		/*
		cout << setw(25) << boughtBooks->getQuant() << "  " << boughtBooks->getISBN() << "\t\t" << boughtBooks->getTitle() 
			<< boughtBooks->getRetail() << "\t\t\t" << boughtBooks->getTotal() << endl;
		// increment pointer
		boughtBooks++;
		*/
		cout << b.at(index).getQuant() << "     " << b.at(index).getISBN() << "\t\t" << b.at(index).getTitle() << "\t\t\t"
			<< b.at(index).getRetail() << "\t" << b.at(index).getTotal() << endl;
		
	}
	// decrement pointer
	/*
	for (index = 0; index < amount; index++)
	{
		boughtBooks--;
	}
	*/
	cout << "-------------------------------------------------------------------------------------" << endl << endl;
	cout << "\t\t\t" << "Subtotal $" << getTotal(amount, b/*boughtBooks*/) << endl;
	cout << "\t\t\t" << "Tax      $" << TAX << endl;
	cout << "\t\t\t" << "Total    $" << getTotal(amount, b/*boughtBooks*/) * TAX << endl << endl;
	cout << "Thank you for shopping at Team 1's Bookstore!" << endl;

	// delete pointer
	//delete[] boughtBooks;
}
#endif //REPORT_DRIVER