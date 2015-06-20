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

Cashier::Cashier(string fileName) : Interface(fileName) {
	printCashierMenu();
}

double Cashier::getTotalCost(vector <Book> b)
{
	double total = 0;
	uint index;

	for (index = 0; index < b.size(); index++)
	{
		total += b[index].getTotal();
	}
	return total;
}

int Cashier::getBook(string id)
{
	uint index;

	// find the book with the right title by iterating through the vector (linear search)
	for (index = 0; index < books.size(); index++)
	{
		if (books[index].getTitle() == id || books[index].getISBN() == id)
		{
			if (books[index].getQuant() <= 0)
			{
				cout << "This book does not exist in our database and cannot be purchased." << endl;
				return -1;
			}
			return index;
		}
	}
	cout << "For some reason, we could not find your book with the given information. Sorry for the inconvenience." << endl;
	return -1;
}

void Cashier::decrementBookQuant(int index)
{
	// find the book with the right title by iterating through the vector (linear search)
	if (books[index].getQuant() <= 0)
	{
		cout << "This book is out of stock and cannot be purchased." << endl;
	}
	else books[index].quantity -= 1;
}

void Cashier::printCashierMenu()
{
	int index = 0;
	int amount = 0;
	string purchase;
	vector <Book> b;
	b.clear();
	b.reserve(10);
	time_t t = time(0);
	struct tm * now = localtime(&t);

	// establish which book(s) are being purchased, the book objects in the vector
	// a loop type to get books

	// dynamically allocate a local pointer to hold the books and then add values to that pointer
	
	cout << "How many books are you purchasing?" << endl;
	cin >> amount;
	cin.ignore();

	for (index = 0; index < amount; index++)
	{
		cout << "What book are you purchasing? Type in the Title." << endl;
		getline(cin, purchase);

		// add books from main vector into new vector for cashier purchases
		// only add books that can be found
		int buy = getBook(purchase);
		if (buy >= 0){
			b.push_back(books[buy]);
			decrementBookQuant(buy);
		}
	}
	
	cout << "\nTeam 1 Book Sellers" << endl << endl;
	cout << "Date: " << (now->tm_mon + 1) << '/' << now->tm_mday << '/' << (now->tm_year + 1900) << endl << endl;
	cout << "Qty   " << "ISBN\t\t" << setw(30) << left << "Title\t\t" << "Price\t" << "Total" << endl;
	// Write out each book's information
	for (index = 0; index < b.size(); index++)
	{
		cout << b[index].getQuant() << "     " << b[index].getISBN() << "\t" << setw(30) << left << b[index].getTitle()
			<< "\t\t$" << setprecision(2) << fixed << b[index].getRetail() << "\t" << "$" << b[index].retail + b[index].retail * TAX << endl;
	}

	cout << "-------------------------------------------------------------------------------------" << endl << endl;
	cout << setprecision(2) << fixed << "\t\t\t" << "Subtotal " << setw(6) << right << "$" << getTotalCost(b) << endl;
	cout << setprecision(2) << fixed << "\t\t\t" << "Tax      " << setw(6) << right << "$" << (getTotalCost(b) * TAX) << endl;
	cout << setprecision(2) << fixed << "\t\t\t" << "Total    " << setw(6) << right << "$" << (getTotalCost(b) + (getTotalCost(b) * TAX)) << endl << endl;
	cout << "Thank you for shopping at Team 1's Bookstore!" << endl;

}
#endif //REPORT_DRIVER