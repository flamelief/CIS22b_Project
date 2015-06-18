#define _CRT_SECURE_NO_WARNINGS
#ifndef REPORT_DRIVER
// Implementation for Cashier

#include <iostream>
#include <iomanip>
#include <ctime>

#include "Cashier.h"
#include "Book.h"

using namespace std;

Cashier::Cashier() : Interface() {}

Cashier::Cashier(string fileName) : Interface(fileName) {}

/*Price Cashier::getTotal(int size, Book * b)
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
}*/

double Cashier::getTotalCost(int size, vector <Book> b)
{
	double total = 0;
	int index;

	for (index = 0; index < size; index++)
	{
		total += b.at(index).getTotal();
	}
	return total;
}

Book Cashier::getBook(string id)
{
	int index;
	Book dummy;

	// find the book with the right title by iterating through the vector (linear search)
	for (index = 0; index < books.size(); index++)
	{
		if ((books.at(index).getTitle() == id))
		{
			if (books.at(index).getQuant() <= 0)
			{
				cout << "This book does not exist in our database and cannot be purchased." << endl;
				return dummy;
			}
			return books.at(index);
		}
	}
	cout << "For some reason, we could not find your book with the given information. Sorry for the inconvenience." << endl;
	return dummy;
}

void Cashier::decrementBookQuant(string id)
{
	int index;
	Book dummy;
	//string tryAgain;
	/*string userInput;
	// Find which book to decrement by ISBN or Title
	cout << "Book to purchase by ISBN or title:";
	cin >> userInput;*/
	
	// find the book with the right title by iterating through the vector (linear search)
	for (index = 0; index < books.size(); index++)
	{
		if ( (books.at(index).getTitle() == id) )
		{
			if (books.at(index).getQuant() <= 0)
			{
				cout << "This book does not exist in our database and cannot be purchased." << endl;
				return;
			}
			books.at(index).quantity -= 1;
			return;
		}
	}
	
	//do {
	cout << "For some reason, we could not find your book with the given information. Sorry for the inconvenience." << endl;
	return;
	//cin >> tryAgain;
	//if (tryAgain == "q")
	//{
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

void Cashier::printCashierMenu()
{
	int index = 0;
	int amount = 0;
	string purchase;
	//Book goodBuy;
	vector <Book> b;
	time_t t = time(0);
	struct tm * now = localtime(&t);

	// establish which book(s) are being purchased, the book objects in the vector
	// a loop type to get books

	// dynamically allocate a local pointer to hold the books and then add values to that pointer
	
	cout << "How many books are you purchasing?" << endl;
	cin >> amount;
	cin.ignore();
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
		cout << "What book are you purchasing? Type in the Title." << endl;
		getline(cin, purchase);

		// add books from main vector into new vector for cashier purchases
		// only add books that can be found
		//goodBuy = decrementBookQuant(purchase);
		//if (goodBuy != dummy)
		b.push_back(getBook(purchase));
		decrementBookQuant(purchase);
		
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
	
	cout << "\nTeam 1 Book Sellers" << endl << endl;
	cout << "Date: " << (now->tm_mon + 1) << '/' << now->tm_mday << '/' << (now->tm_year + 1900) << endl << endl;
	cout << "Qty   " << "ISBN\t\t" << setw(30) << left << "Title\t\t" << "Price\t" << "Total" << endl;
	// Write out each book's information
	for (index = 0; index < amount; index++)
	{
		/*
		cout << setw(25) << boughtBooks->getQuant() << "  " << boughtBooks->getISBN() << "\t\t" << boughtBooks->getTitle() 
			<< boughtBooks->getRetail() << "\t\t\t" << boughtBooks->getTotal() << endl;
		// increment pointer
		boughtBooks++;
		*/
		cout << (b.at(index)).getQuant() << "     " << (b.at(index)).getISBN() << "\t" << setw(30) << left << (b.at(index)).getTitle()
			<< "\t\t$" << setprecision(2) << fixed << (b.at(index)).getRetail() << "\t" << "$" << b.at(index).retail + (b.at(index)).retail * TAX << endl;
	}
	// decrement pointer
	/*
	for (index = 0; index < amount; index++)
	{
		boughtBooks--;
	}
	*/
	cout << "-------------------------------------------------------------------------------------" << endl << endl;
	cout << setprecision(2) << fixed << "\t\t\t" << "Subtotal " << setw(6) << right << "$" << getTotalCost(amount, b) << endl;
	cout << setprecision(2) << fixed << "\t\t\t" << "Tax      " << setw(6) << right << "$" << (getTotalCost(amount, b) * TAX) << endl;
	cout << setprecision(2) << fixed << "\t\t\t" << "Total    " << setw(6) << right << "$" << (getTotalCost(amount, b) + (getTotalCost(amount, b) * TAX)) << endl << endl;
	cout << "Thank you for shopping at Team 1's Bookstore!" << endl;

	// delete pointer
	//delete[] boughtBooks;
}
#endif //REPORT_DRIVER